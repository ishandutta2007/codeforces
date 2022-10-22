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
const int N = 1e5 + 7, K = 101;
int mem[K][N], a[N];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int k = 1; k < K; ++k) {
        for (int i = n; i; --i) {
            int to = i + k + a[i];
            if (to > n) 
                mem[k][i] = 1;
            else
                mem[k][i] = mem[k][to] + 1;
        }   
    }           
    int q;
    cin >> q;
    while (q--) {
        int p, k;
        cin >> p >> k;
        if (k < K) {
            cout << mem[k][p] << endl;
        }   
        else {
            int ans = 0;
            while (p <= n) {
                ++ans;
                p += a[p] + k;
            }   
            cout << ans << endl;
        }   
    }   
}