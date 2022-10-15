#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define umap unordered_map
#define flush fflush(stdout)
#define all(v) v.begin(),v.end()
#define st first
#define nd second
#define ln '\n'
#define MAX 1000000009
#define MOD 1000000007
#define N 2005
using namespace std;
typedef long long ll;
typedef pair<int ,int > pii;
int n, h, l, r, x, arr[N], dp[N][N];
int DP(int now, int hour){
    if(dp[now][hour] != -1)return dp[now][hour];
    int s1 = (hour + arr[now]) % h, s2 = (hour + arr[now] - 1) % h;
    if(now == n - 1)return (s1 <= r && s1 >= l) || (s2 <= r && s2 >= l);
    return dp[now][hour] =  + max(DP(now + 1, s1) + (s1 <= r && s1 >= l), DP(now + 1, s2) + (s2 <= r && s2 >= l));
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    memset(dp, -1, sizeof dp);
    cin >> n >> h >> l >> r;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << DP(0, 0) ;
}