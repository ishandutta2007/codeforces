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

const int N = 2e8 + 7;
char t[N];
int a[5007];

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    for (int i = 1; i < N; ++i) 
        t[i] = 21;
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i) {
        for (int x = 1; x <= k; ++x) {
            int sum = a[i] * x;
            if (sum < N)
                t[sum] = min(t[sum], (char)x);
        }   
    }   
    int q;
    cin >> q;
    while (q--) {
        int w;
        cin >> w;

        int ans = 21;
        for (int i = 0; i < n; ++i) {
            for (int x = 1; x <= k; ++x) {
                int sum = a[i] * x;
                if (sum <= w)
                    ans = min(ans, t[w - sum] + x);
            }   
        }   

        if (ans <= k)
            cout << ans << '\n';
        else
            cout << "-1\n";
    }   
}