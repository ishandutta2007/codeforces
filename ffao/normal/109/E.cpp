#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")

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
 
 
 
int tab[300010];
 
int count2(ll a) {
    return tab[a%100000] + tab[a/100000];
}
 
ll minc(ll a, ll k) {
    ll r = 1;
    while (a % 10 == 0 && k % 10 == 0) {
        a /= 10;
        k /= 10;
        r *= 10;
    }
    return r;
}
 
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    clock_t z = clock();    
    for (int i = 1; i <= 300000; i++) {
        tab[i] = tab[i/10];
        if (i % 10 == 4 || i % 10 == 7) tab[i]++;
    }
 
    int a, l;
    cin >> a >> l;
 
    ll p10 = 1;
    while (p10 * 10 <= l) p10 *= 10;
 
    if (p10 >= 100000) {
        for (ll st = a+p10; ; st+=p10) {
            // dbg(st);
            bool ok = true;
 
            for (int i = 0; ok && i <= min(l, 350000000); i += minc(a+i,st+i)) {
                // if ((!(i & 16777215)) && (clock() - z) > 3.7 * CLOCKS_PER_SEC) break;
                if (count2(st+i) != count2(a+i)) ok = false;
                if (count2(st+l-1-i) != count2(a+l-1-i)) ok = false;
                if (i > 0) dbg(st,i);
                if (ok == false) dbg(i);
            }
 
            if (ok) {
                cout << st << endl;
                return 0;
            }
        }
    }
    else {
        for (ll st = a+p10; ; st+=p10) {
            // dbg(st);
            bool ok = true;
 
            for (int i = 0; ok && i <= min(l/2, 350000000); i++) {
                // if ((!(i & 16777215)) && (clock() - z) > 3.7 * CLOCKS_PER_SEC) break;
                if (count2(st+i) != count2(a+i)) ok = false;
                if (count2(st+l-1-i) != count2(a+l-1-i)) ok = false;
                if (i > 0) dbg(st,i);
                if (ok == false) dbg(i);
            }
 
            if (ok) {
                cout << st << endl;
                return 0;
            }
        }
    }
 
    return 0;
}