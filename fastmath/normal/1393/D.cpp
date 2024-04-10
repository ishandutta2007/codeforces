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


const int N = 2007;
string a[N];
int dp[N][N], ans[N][N];

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    vector <ii> vx = { {1, 0}, {-1, n - 1} }, vy = { {1, 0}, {-1, m - 1} };

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            ans[i][j] = N;

    for (auto ex : vx) {
        for (auto ey : vy) {
            int dx = ex.f;
            int dy = ey.f;
            for (int i = ex.s; i < n && i >= 0; i += dx) {
                for (int j = ey.s; j < m && j >= 0; j += dy) {
                    dp[i][j] = N;

                    if (i - dx < 0 || i - dx >= n || a[i-dx][j] != a[i][j])
                        dp[i][j] = 1;
                    else
                        dp[i][j] = min(dp[i][j], dp[i-dx][j]+1);

                    if (j - dy < 0 || j - dy >= m || a[i][j-dy] != a[i][j])
                        dp[i][j] = 1;
                    else
                        dp[i][j] = min(dp[i][j], dp[i][j-dy]+1);

                    ans[i][j] = min(ans[i][j], dp[i][j]);
                }
            }
        }   
    }

    int sum = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            sum += ans[i][j];
    cout << sum << endl;        
}