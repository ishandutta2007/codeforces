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
        int n; scanf("%d", &n); n *= 2;
        static char s[maxn + 5]; scanf("%s", s + 1);
        static int ps[maxn + 5];
        rep(i, 1, n) ps[i] = s[i] == '(' ? 1 : -1;
        rep(i, 1, n) ps[i] += ps[i - 1];
        if(*min_element(ps + 1, ps + n + 1) == 0) puts("0");
        else
        {
            int l = 1, r = n;
            while(ps[l] >= 0) l++;
            while(ps[r] >= 0) r--;
            int L = max_element(ps, ps + l) - ps + 1;
            int R = max_element(ps + r, ps + n + 1) - ps;
            reverse(s + L, s + R + 1);
            int sum = 0, ok = 1;
            rep(i, 1, n) 
            {
                sum += s[i] == '(' ? 1 : -1;
                if(sum < 0) ok = 0;
            }
            if(ok)
            {
                puts("1");
                printf("%d %d\n", L, R);
            }
            else
            {
                int pos = max_element(ps + 1, ps + n + 1) - ps;
                puts("2");
                printf("%d %d\n", 1, pos);
                printf("%d %d\n", pos + 1, n);
            }
        }
    }
    return 0;
}