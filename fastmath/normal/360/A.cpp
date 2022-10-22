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
#define Time (double)clock()/CLOCKS_PER_SEC
const int N = 5007, INF = 1000 * 1000 * 1000;
int add[N], mx[N], cur[N];
int t[N], l[N], r[N], m[N];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    for (int i = 0; i < N; ++i)
        mx[i] = INF;
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < q; ++i) {
        cin >> t[i];
        cin >> l[i] >> r[i] >> m[i];
        if (t[i] == 1) {
            for (int j = l[i]; j <= r[i]; ++j)
                add[j] += m[i];
        }
        else {
            for (int j = l[i]; j <= r[i]; ++j)
                mx[j] = min(mx[j], m[i] - add[j]);
        }   
    }   
    for (int i = 1; i <= n; ++i)
        cur[i] = mx[i];
    for (int i = 0; i < q; ++i) {
        if (t[i] == 1) {
            for (int j = l[i]; j <= r[i]; ++j)
                cur[j] += m[i];
        }   
        else {
            int t = 0;
            for (int j = l[i]; j <= r[i]; ++j)
                t = max(t, cur[j]);
            if (t < m[i]) {
                cout << "NO\n";
                exit(0);
            }   
        }   
    }   
    cout << "YES\n";
    for (int i = 1; i <= n; ++i)
        cout << mx[i] << ' ';
    cout << endl;
}