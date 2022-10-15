#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define umap unordered_map
#define all(v) v.begin(),v.end()
#define st first
#define nd second
#define L (nd<<1)
#define R L|1
#define mid (s + e)>>1
#define ln '\n'
#define MAX (1<<30)
#define MOD 1000000007
#define mod 998244353
#define N 500005
using namespace std;
typedef long long ll;
typedef pair<ll ,ll> pii;
typedef vector<int> vi;
ll n, x, arr[N], dp[N][2], ct[N];
ll DP(int ind, int vis){
  if(dp[ind][vis]!=-1)return dp[ind][vis];
  if(ind == n - 1)return dp[ind][vis] = (vis ? 0 : arr[ind] * ct[arr[ind]]);
  ll ans = -1;
  ans = max(ans, DP(ind + 1, 0));
  if(!vis)ans = max(ans, DP(ind + 1, (arr[ind + 1] == arr[ind] + 1)) + (ll)arr[ind] * ct[arr[ind]]);
  return dp[ind][vis] = ans;
}
int main(){
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin); 
  freopen("out.txt", "w", stdout);
  #endif
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);cout.tie(NULL);
  cin >> n;
  set <ll> s; 
  for(int i =0 ; i< n; i++){
    cin >> x;
    ct[x]++;
    s.insert(x);
  }
  int i = 0;
  for(auto a : s){
    arr[i++] = a;
  }
  n = i;
  memset(dp, -1, sizeof dp);
  cout << DP(0, 0);


}