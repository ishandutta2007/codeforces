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
const int N = 1e5 + 7;
int len[N], ans[N], suff[N];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n, m;
    cin >> n >> m;
    vector <ii> a;
    int sum = 0;
    for (int i = 1; i <= m; ++i) {
        cin >> len[i];
        a.app(mp(len[i], i));
        sum += len[i];
    }   

    if (sum < n) {
        cout << -1 << endl;
        exit(0);
    }   
 
    suff[m] = -1;
    for (int i = m - 1; i >= 0; --i)
        suff[i] = max(suff[i + 1], i + a[i].f);
 
    int l = 1, r = 1;
    for (int i = 0; i < m; ++i) {
        //p + suff[i + 1] <= n + 1
        //p <= n + 1 - suff[i + 1]
        ans[a[i].s] = min(r, n + 1 - (suff[i] - i));
 
        if (ans[a[i].s] < l) {
            cout << -1 << endl;
            exit(0);
        }   
 
        l = ans[a[i].s] + 1;
        r = ans[a[i].s] + a[i].f;
    }
 
    for (int i = 1; i <= m; ++i)
        cout << ans[i] << ' ';
    cout << endl;
}