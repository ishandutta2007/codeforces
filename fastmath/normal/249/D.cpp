#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcount
#define ll long long
#define mp make_pair
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define Time (double)clock()/CLOCKS_PER_SEC
#define double long double
const int N = 2e5 + 7;
const double EPS = 1e-8;
int dp[N];
bool comp(ii a, ii b) {
    return a.f < b.f || (a.f == b.f && a.s > b.s);
}   
void nvp(vector <ii> a) {
    for (int i = 1; i < N; ++i)
        dp[i] = N;
    sort(all(a), comp);
    for (auto p : a) 
        dp[lower_bound(dp, dp + N, p.s) - dp] = p.s;
    for (int i = N - 1; ; --i) 
        if (dp[i] != N) {
            cout << i << '\n';
            exit(0);
        }   
}   
pair <double, double> a[N];
double gett(double a, double b) {
    return (a - b) / (1 + a * b);
}   
bool eq(double a, double b) {
    return abs(a - b) < EPS;
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n;
    double A, B, C, D;
    char t;
    cin >> n >> A >> t >> B >> C >> t >> D;
    double ang = -atan2(A, B);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].f >> a[i].s;
        a[i] = mp(a[i].f * cos(ang) - a[i].s * sin(ang), a[i].f * sin(ang) + a[i].s * cos(ang));
    }   
    double tg = tan(atan2(C, D) - atan2(A, B));
    //double tg = gett(C/D, A/B);
    vector <double> c;
    for (int i = 0; i < n; ++i) {
        a[i].f -= a[i].s / tg;
        c.app(a[i].f); c.app(a[i].s);
    }   
    sort(all(c)); c.resize(unique(all(c), eq) - c.begin());
    #ifdef HOME
    for (int i = 0; i < n; ++i)
        cout << a[i].f << ' ' << a[i].s << '\n';
    for (auto e : c) 
        cout << e << ' ';
    cout << '\n';
    #endif
    vector <ii> q;
    for (int i = 0; i < n; ++i) 
        if (a[i].f > 0 && a[i].s > 0) {
            int l = -1, r = c.size();
            while (l < r - 1) {
                int m = (l + r) >> 1;
                if (c[m] + EPS < a[i].f) l = m;
                else r = m;
            }   
            int x = r + 1;

            l = -1; r = c.size();
            while (l < r - 1) {
                int m = (l + r) >> 1;
                if (c[m] + EPS < a[i].s) l = m;
                else r = m;
            }   
            int y = r + 1;

            q.app(mp(x, y));
        }   
    nvp(q);
}