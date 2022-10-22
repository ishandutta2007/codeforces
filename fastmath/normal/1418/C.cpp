#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcountll
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC
#define debug(x) std::cout << #x << ": " << x << '\n';

const int N = 2e5+7;
int dp[N][2];

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(20); 
    #endif

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <int> a(n);

        for (int i = 0; i <= n; ++i)
            for (int j = 0; j < 2; ++j)
                dp[i][j] = N;

        dp[0][0] = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 2; ++j) {
                int sum = 0;
                for (int k = 1; k <= 2 && k <= n - i; ++k) {
                    sum += a[i + k - 1];
                    dp[i + k][j ^ 1] = min(dp[i + k][j ^ 1], dp[i][j] + sum * (j ^ 1));
                }   
            }   
        }   
        cout << min(dp[n][0], dp[n][1]) << endl;
    }   

}