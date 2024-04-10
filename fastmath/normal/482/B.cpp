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
int n, m;
int l[N], r[N], x[N];

int add[N];
bool a[N];
int pref[N];
int ans[N];

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> l[i] >> r[i] >> x[i];
        --l[i]; --r[i];
    }
    for (int b = 0; b < 30; ++b) {
        for (int i = 0; i < N; ++i)
            add[i] = 0;
        for (int i = 0; i < m; ++i) {
            if ((x[i] >> b) & 1) {
                ++add[l[i]];
                --add[r[i] + 1];
            }
        }   
        for (int i = 0; i < n; ++i) {
            if (i)
                add[i] += add[i - 1];
            a[i] = add[i]; 
            pref[i + 1] = pref[i] + a[i];
        }   
        for (int i = 0; i < m; ++i) {
            int sum = pref[r[i] + 1] - pref[l[i]];
            if (sum == r[i] - l[i] + 1 && !((x[i] >> b) & 1)) {
                cout << "NO\n";
                exit(0);
            }   
        }   
        for (int i = 0; i < n; ++i)
            if (a[i])
                ans[i] += 1 << b;
    }   
    cout << "YES\n";
    for (int i = 0; i < n; ++i)
        cout << ans[i] << ' ';
    cout << '\n';
}