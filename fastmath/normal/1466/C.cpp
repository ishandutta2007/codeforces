#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcountll
#define ll long long
#define mp make_pair
#define x first
#define y second
#define Time (double)clock()/CLOCKS_PER_SEC
#define debug(x) std::cout << #x << ": " << x << '\n';
#define FOR(i, n) for (int i = 0; i < n; ++i)
#define pb push_back
#define trav(a, x) for (auto& a : x)
using vi = vector<int>;
template <typename T>
std::ostream& operator <<(std::ostream& output, const pair <T, T> & data)
{
    output << "(" << data.x << "," << data.y << ")";
    return output;
}
template <typename T>
std::ostream& operator <<(std::ostream& output, const std::vector<T>& data)
{
    for (const T& x : data)
        output << x << " ";
    return output;
}
//ll div_up(ll a, ll b) { return a/b+((a^b)>0&&a%b); } // divide a by b rounded up
//ll div_down(ll a, ll b) { return a/b-((a^b)<0&&a%b); } // divide a by b rounded down 
#define tcT template<class T
#define tcTU tcT, class U
tcT> using V = vector<T>; 
tcT> void re(V<T>& x) { 
    trav(a, x)
        cin >> a;
}
tcT> bool ckmin(T& a, const T& b) {
    return b < a ? a = b, 1 : 0; 
} // set a = min(a,b)
tcT> bool ckmax(T& a, const T& b) {
    return a < b ? a = b, 1 : 0; 
}

const int N = 1e5+7;
int dp[N][2][2];

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.size();
        FOR (i, n + 1)
            FOR (j, 2)
                FOR (k, 2)
                    dp[i][j][k] = N;
        dp[0][1][1] = 0;
        //0 - not change

        FOR (i, n) {
            FOR (j, 2) {
                FOR (k, 2) {
                    if (dp[i][j][k] == N)
                        continue;
                    if ( j || (s[i - 2] != s[i]) ) {
                        if ( k || (s[i - 1] != s[i]) ) {
                            ckmin(dp[i + 1][k][0], dp[i][j][k]);
                        }   
                    }   
                    ckmin(dp[i + 1][k][1], dp[i][j][k] + 1);
                }   
            }   
        }   

        int ans = N;
        FOR (i, 2)
            FOR (j, 2)
                ckmin(ans, dp[n][i][j]);

        cout << ans << endl;
    }   

}