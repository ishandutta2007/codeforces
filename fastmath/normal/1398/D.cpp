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

const int N = 207;
int dp[N][N][N];

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int r, g, b;
    cin >> r >> g >> b;
    vector <int> R(r), G(g), B(b);
    for (int i = 0; i < r; ++i)
        cin >> R[i];
    for (int i = 0; i < g; ++i)
        cin >> G[i];
    for (int i = 0; i < b; ++i)
        cin >> B[i];
    auto f = [&] (vector <int> &a) { sort(all(a)); reverse(all(a)); };
    f(R); f(G); f(B);
    int ans = 0;
    for (int i = 0; i <= r; ++i) {
        for (int j = 0; j <= g; ++j) {
            for (int k = 0; k <= b; ++k) {
                auto rel = [&] (int &a, int b) { a = max(a, b); };
                rel(ans, dp[i][j][k]);
                if (i < r && j < g)
                    rel(dp[i + 1][j + 1][k], dp[i][j][k]+R[i]*G[j]);
                if (i < r && k < b)
                    rel(dp[i + 1][j][k + 1], dp[i][j][k]+R[i]*B[k]);
                if (j < g && k < b)
                    rel(dp[i][j+1][k+1], dp[i][j][k]+G[j]*B[k]);
            }   
        }   
    }   
    cout << ans << endl;
}