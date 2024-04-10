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
//a = y1 - y2
//b = x2 - x1
//c = x1 * y2 - x2 * y1

const int N = 1007;
ii p[N];
vector <int> t[N * N];

void compr(vector <int> &a) {
    sort(all(a)); a.resize(unique(all(a)) - a.begin());
}   
void compr(vector <ii> &a) {
    sort(all(a)); a.resize(unique(all(a)) - a.begin());
}   

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n; cin >> n;
    for (int i = 0; i < n; ++i) cin >> p[i].f >> p[i].s;
    vector <ii> l;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int a = p[i].s - p[j].s;
            int b = p[j].f - p[i].f;
            int c = p[i].f * p[j].s - p[i].s * p[j].f;

            int d = 0;
            d = __gcd(d, abs(a));
            d = __gcd(d, abs(b));
            d = __gcd(d, abs(c));

            a /= d; b /= d; c /= d;
            if (a < 0 || (a == 0 && b < 0)) {
                a = -a; b = -b; c = -c;
            }   
            l.app(mp(a, b));
        }
    }   
    compr(l);
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int a = p[i].s - p[j].s;
            int b = p[j].f - p[i].f;
            int c = p[i].f * p[j].s - p[i].s * p[j].f;

            int d = 0;
            d = __gcd(d, abs(a));
            d = __gcd(d, abs(b));
            d = __gcd(d, abs(c));

            a /= d; b /= d; c /= d;
            if (a < 0 || (a == 0 && b < 0)) {
                a = -a; b = -b; c = -c;
            }   
            t[lb(all(l), mp(a, b)) - l.begin()].app(c);
        }
    }   
    int ans = 0;
    int all = 0;
    for (int i = 0; i < l.size(); ++i) {
        compr(t[i]);
        int n = t[i].size();
        all += n;
        ans -= n * (n - 1) / 2;
    }                               
    cout << ans + all * (all - 1) / 2 << '\n';
}