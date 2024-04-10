 #include "bits/stdc++.h"
#define rep(i, a, n) for(auto i = a; i <= n; i++)
#define per(i, a, n) for(auto i = n; i >= a; i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define all(a) a.begin(), a.end()
#define sz(a) (int)(a).size()
template<class T> inline bool chmax(T &a, T b) { if(a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, T b) { if(b < a) { a = b; return 1; } return 0; }
using namespace std;

template<class A, class B> string to_string(pair<A, B> p);
string to_string(const string &s) { return '"' + s + '"'; }
string to_string(const char *s) { return to_string((string) s); }
string to_string(char c) { return "'" + string(1, c) + "'"; }
string to_string(bool x) { return x ? "true" : "false"; }
template<class A> string to_string(A v)
{
    bool first = 1;
    string res = "{";
    for(const auto &x: v) 
    {
        if (!first) res += ", ";
        first = 0;
        res += to_string(x);
    }
    res += "}";
    return res;
}
template<class A, class B> string to_string(pair<A, B> p) { return "(" + to_string(p.FI) + ", " + to_string(p.SE) + ")"; }

void debug_out() { cerr << endl; }
template<class Head, class... Tail> void debug_out(Head H, Tail... T) 
{
    cerr << " " << to_string(H);
    debug_out(T...);
}
#ifndef ONLINE_JUDGE
    #define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
    #define debug(...) if(0) puts("No effect.")
#endif

using ll = long long;
// using LL = __int128;
using pii = pair<int,int>;
using vi = vector<int>;
using db = double;
using ldb = long double;

const int maxn = 200'000;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;

int main()
{
    int cas; scanf("%d", &cas); while(cas--)
    {
        int a, b, c, d; scanf("%d%d%d%d", &a, &b, &c, &d);
        static char s[maxn + 5]; scanf("%s", s + 1);
        int n = strlen(s + 1);
        int cnt[2] = {};
        rep(i, 1, n) cnt[s[i] - 'A']++;
        if(a + c + d != cnt[0]) puts("NO");
        else
        {
            int share = 0;
            multiset<int> S[2];
            char last = 'C';
            int len = 0;
            auto work = [&](int l, char ed)
            {
                // debug(cas, l, ed);
                if(l & 1) share += l / 2;
                else if(ed == 'B') S[0].insert(l / 2);
                else S[1].insert(l / 2);
            };
            rep(i, 1, n)
            {
                if(s[i] == last) work(len, last), len = 0;
                last = s[i];
                len++;
            }
            work(len, last);
            while(c && sz(S[0]))
            {
                int x = *S[0].begin(); S[0].erase(S[0].begin());
                int mn = min(x, c);
                c -= mn;
                x -= mn;
                if(x) S[0].insert(x);
            }
            while(d && sz(S[1]))
            {
                int x = *S[1].begin(); S[1].erase(S[1].begin());
                int mn = min(x, d);
                d -= mn;
                x -= mn;
                if(x) S[1].insert(x);
            }
            rep(i, 0, 1) for(auto x: S[i]) if(x) share += x - 1;
            puts(share >= c + d ? "YES" : "NO");
        }
    }
    return 0;
}