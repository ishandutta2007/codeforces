#include<bits/stdc++.h>
using namespace std;
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

const int N = 81, INF = 1e9;
int a[N];
int dp[N][N][N * N / 2][2]; // i - nulls, j - ones, k - ops
int cnt[2];

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(20); 
    #endif
    int n;
    cin >> n;
    int cur = 0;
    vector <int> pos;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        cnt[a[i]]++;
        if (a[i])
            pos.app(cnt[0]);            
    }   
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            for (int k = 0; k < (N * N) / 2; ++k)
                dp[i][j][k][0] = dp[i][j][k][1] = INF;

    auto rel = [&] (int &a, int b) {
        a = min(a, b);
    };  

    dp[0][0][0][0] = 0;
    dp[0][0][0][1] = 0;

    for (int i = 0; i <= cnt[0]; ++i) {
        for (int j = 0; j <= cnt[1]; ++j) {
            for (int k = 0; k <= n * (n - 1) / 2; ++k) {

                {
                int x = min(dp[i][j][k][0], dp[i][j][k][1]);
                if (x < INF && j < cnt[1]) {
                    rel(dp[i][j + 1][k + abs(i - pos[j])][1], x);
                }
                }

                {
                int x = dp[i][j][k][1];
                if (x < INF) {
                    for (int add = 1; i + add <= cnt[0]; ++add) {
                        rel(dp[i + add][j][k][0], x + add * (add - 1) / 2);
                    }   
                }   
                }
                
            }   
        }   
    }                   

    int al = cnt[0] * (cnt[0] - 1) / 2;
    int ans = 0;
    for (int i = 0; i <= n * (n - 1) / 2; ++i) {
        ans = max(ans, al - dp[cnt[0]][cnt[1]][i][0]);
        ans = max(ans, al - dp[cnt[0]][cnt[1]][i][1]);
        cout << ans << ' ';
    }   
    cout << endl;

    #ifdef HOME
    cout << Time << endl;
    #endif
}