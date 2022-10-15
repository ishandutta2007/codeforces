#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define umap unordered_map
#define all(v) v.begin(),v.end()
#define st first
#define nd second
#define ln '\n'
#define MAX 1000000009
#define MOD 1000000007
#define N 2006
using namespace std;
typedef long long ll;
typedef pair<ll ,ll> pii;
typedef vector<int> vi;   
int a, m, n, l, r, dp[N][N], ex[N];
bool rain[N];     
int DP(int now, int mu){
    // cout << dp[now][mu] << ln;
    if(dp[now][mu] != -1)return dp[now][mu];
    //cout << " asd" << ln;
    dp[now][mu] = MAX;
    if(rain[now] && mu == N - 1){
        return dp[now][mu] = MAX;
    }
    if(now == a){
        return dp[now][mu] = 0;
    }
    if(ex[now] != -1){
        dp[now][mu] = min(dp[now][mu], ex[now] + DP(now + 1, now));
    }
    //cout << "asd" << ln;
    dp[now][mu] = min(dp[now][mu], (mu == N - 1 ? 0 : ex[mu])+ DP(now + 1, mu));
    if(!rain[now + 1])dp[now][mu] = min(dp[now][mu], DP(now + 1, N -1));
    //cout << now << " " << mu << " " << dp[now][mu] << ln;
    return dp[now][mu];
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    memset(dp, -1, sizeof dp);
    memset(ex, -1, sizeof ex);
    cin >> a >> m >> n;
    while(m--){
        cin >> l >> r;
        for(int i = l + 1; i <= r; i++){
            rain[i] = 1;
        }
    }
    while(n--){
        cin >> l >> r;
        ex[l] = (ex[l] == -1 ? r : min(ex[l], r));
    }
    //for(int i = 0; i <= a; i++)cout << rain[i] << " ";
    int ans = DP(0, N - 1);
    if(ex[0] != -1){
        ans = min(ans, DP(0, 0));
    }
    cout << (ans >= MAX ? -1 : ans);

}