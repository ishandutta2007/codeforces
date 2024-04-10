#if 1
#ifdef LOCAL
#define _GLIBCXX_DEBUG 1
#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define dbg(...) 0
#endif

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)

typedef string str;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define ts to_string
str ts(char c) { return str(1,c); }
str ts(bool b) { return b ? "true" : "false"; }
str ts(const char* s) { return (str)s; }
str ts(str s) { return s; }
template<class A> str ts(complex<A> c) { stringstream ss; ss << c; return ss.str(); }
str ts(vector<bool> v) { str res = "{"; F0R(i,sz(v)) res += char('0'+v[i]);	res += "}"; return res; }
template<size_t SZ> str ts(bitset<SZ> b) { str res = ""; F0R(i,SZ) res += char('0'+b[i]); return res; }
template<class A, class B> str ts(pair<A,B> p);
template<class T> str ts(T v) { bool fst = 1; str res = "{"; for (const auto& x: v) {if (!fst) res += ", ";	fst = 0; res += ts(x);}	res += "}"; return res;}
template<class A, class B> str ts(pair<A,B> p) {return "("+ts(p.f)+", "+ts(p.s)+")"; }
 
template<class A> void pr(A x) { cout << ts(x); }
template<class H, class... T> void pr(const H& h, const T&... t) { pr(h); pr(t...); }
void ps() { pr("\n"); }
template<class H, class... T> void ps(const H& h, const T&... t) { pr(h); if (sizeof...(t)) pr(" "); ps(t...); }
 
void DBG() { cerr << "]" << endl; }
template<class H, class... T> void DBG(H h, T... t) {cerr << ts(h); if (sizeof...(t)) cerr << ", ";	DBG(t...); }
#endif

int scores[] = {500, 1000, 1500, 2000, 2500, 3000};

int getfrac(int x, int y) {
    int f = 0;
    while (x*2 <= y) {
        x *= 2;
        f++;
        if (f == 5) return f;
    }
    return f;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;

    vi vasya(5);
    vi petya(5);
    vi solved(5);

    for (int i = 0; i < 5; i++) {
        cin >> vasya[i];
        if (vasya[i] != -1) solved[i]++;
    }
    for (int i = 0; i < 5; i++) {
        cin >> petya[i];
        if (petya[i] != -1) solved[i]++;
    }

    for (int i = 0; i < n-2; i++) {
        for (int j = 0; j < 5; j++) {
            int u; cin >> u;
            if (u != -1) solved[j]++;
        }
    }   

    vi frac(5);

    int ans = 1000000007;

    for (int p = 0; p < 7776; p++) {
        // dbg(p);
        int tp = p;
        for (int j = 0; j < 5; j++) {
            frac[j] = (tp % 6);
            tp /= 6;
        }

        int sc = 0;
        for (int j = 0; j < 5; j++) {
            if (vasya[j] != -1) {
                sc += scores[frac[j]] - (scores[frac[j]] / 250) * vasya[j];
            }
            if (petya[j] != -1) {
                sc -= scores[frac[j]] - (scores[frac[j]] / 250) * petya[j];
            }
        }

        if (sc <= 0) continue;

        int th = 0;
        for (int j = 0; j < 5; j++) {
            int curfrac = getfrac(solved[j], n); 

            if (curfrac == frac[j]) continue;

            if (curfrac > frac[j]) {
                int st = 0, ed = 1000000007;
                while (st < ed) {
                    int md = (st+ed)/2;
                    if (getfrac(solved[j] + md, n + md) <= frac[j]) ed = md;
                    else st = md+1;
                }
                th = max(th, st);
            }
            else {
                int st = 0, ed = 1000000007;
                while (st < ed) {
                    int md = (st+ed)/2;
                    if (getfrac(solved[j], n + md) >= frac[j]) ed = md;
                    else st = md+1;
                }
                th = max(th, st);
            }
        }

        for (int j = 0; j < 5; j++) {
            if (vasya[j] == -1 && getfrac(solved[j], n + th) != frac[j]) th = 1000000008;
        }

        // if (th == 1) dbg(frac);
        ans = min(ans, th);
    }

    cout << (ans == 1000000007 ? -1 : ans) << endl;
    return 0;
}