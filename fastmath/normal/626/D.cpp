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
const int N = 40000;
int dp[4][N];
int cnt[N];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    dp[0][20000] = 1;
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    map <int, int> add;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            ++cnt[a[i] - a[j] + 5000];
            ++cnt[a[j] - a[i] + 5000];
        }   
    }   
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < N; ++j) {
            if (!dp[i][j])
                continue;
            if (i < 2) {
                for (int add = 0; add < 5000; ++add)
                    dp[i + 1][j + add - 5000] += dp[i][j] * cnt[add];
            }   
            else {
                for (int add = 5001; add <= 10000; ++add)   
                    dp[i + 1][j + add - 5000] += dp[i][j] * cnt[add];
            }   
        }   
    }   
    int ans = 0;
    for (int i = 20001; i < N; ++i)
        ans += dp[3][i];    
    cout.precision(10);
    double all = n * (n - 1) / 2;
    all = all * all * all;
    cout << ans / all << '\n';
}