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

array<int, 4> read() {
    array<int, 4> ret;

    int x1,y1,x2,y2,x3,y3,x4,y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

    ret[2] = ret[3] = -100000;
    ret[0] = ret[1] = 1000000000;

    ret[0] = min(ret[0], x1);
    ret[0] = min(ret[0], x2);
    ret[0] = min(ret[0], x3);
    ret[0] = min(ret[0], x4);
    ret[2] = max(ret[2], x1);
    ret[2] = max(ret[2], x2);
    ret[2] = max(ret[2], x3);
    ret[2] = max(ret[2], x4);
    
    ret[1] = min(ret[1], y1);
    ret[1] = min(ret[1], y2);
    ret[1] = min(ret[1], y3);
    ret[1] = min(ret[1], y4);
    ret[3] = max(ret[3], y1);
    ret[3] = max(ret[3], y2);
    ret[3] = max(ret[3], y3);
    ret[3] = max(ret[3], y4);
    return ret;
}

bool in(int a, int b, int c) {
    return a <= b && b <= c;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    array<int,4> s1 = read();
    array<int,4> s2 = read();

    
    for (int y = s2[1]; y <= s2[3]; y++) {
        if (y >= s1[1] && y <= s1[3]) {
            int mp = (s2[1] + s2[3]) / 2;
            int sm = s2[0] + abs(y - mp);
            int bg = s2[2] - abs(y - mp);

            if (in(sm,s1[0],bg) || in(sm,s1[2],bg) || in(s1[0],sm,s1[2]) || in(s1[0],bg,s1[2]) ) {
                cout << "YES" << endl;
                return 0;
            }
        }
    }

    cout << "NO" << endl;
    return 0;
}