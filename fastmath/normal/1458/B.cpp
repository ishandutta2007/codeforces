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
#define FOR(i, n) for (int i = 0; i < n; ++i)
#define pb push_back

const int N = 107;
int cap[N], v[N];
int dp[N][N * N];

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    int n;
    cin >> n;

    auto relax = [&] (int &a, int b) {
        a = max(a, b);
    };  

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N * N; ++j)
            dp[i][j] = -1;
    dp[0][0] = 0;

    int S = 0;
    for (int i = 0; i < n; ++i) {
        cin >> cap[i] >> v[i];
        S += v[i];
        for (int k = i; k >= 0; --k) {
            for (int ca = 0; ca < N * N; ++ca) {

                if (dp[k][ca] == -1)
                    continue;

                if (ca + cap[i] < N * N) {
                    relax(dp[k + 1][ca + cap[i]], dp[k][ca] + v[i]);
                }   
            }   
        }               
    }   

    for (int k = 1; k <= n; ++k) {
        int ans = 0;
        for (int ca = 0; ca < N * N; ++ca) {
            if (dp[k][ca] == -1)
                continue;
            ans = max(ans, min(ca * 2, S + dp[k][ca]));
        }   
        cout << ans/2;
        if (ans & 1)
            cout << ".5" << ' ';
        else
            cout << ".0" << ' ';
    }   
    cout << endl;    
}