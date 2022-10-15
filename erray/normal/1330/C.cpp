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
#define MAX (ll)(1<<30)
#define MOD 1000000007
#define mod 998244353
#define N 500005
using namespace std;
typedef long long ll;
typedef pair<ll ,ll> pii;
typedef vector<int> vi;
int n, k, x;
int main(){
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);cout.tie(NULL);  
  cin >> n >> k;
  vi ans, v;
  ll sum = 0;
  for(int i = 0; i < k; i++){
  	cin >> x;
  	sum += x;
  	v.pb(x);
  	if(i + x > n){
  		cout << -1;
  		return 0;
  	}
  }
  if(sum < n){
  	cout << -1;
  	return 0;
  }
  reverse(all(v));
  int nec = n - k - v[0] + 1, lst = n + 1 - v[0];
  ans.pb(lst);
  for(int i = 1; i < k; i++){
  	ans.pb(min(n - v[i] + 1, lst - min(nec + 1, v[i])));
  	nec -= (lst - ans[ans.size() - 1]) - 1;
  	lst = ans[ans.size() - 1];
  }
  if(lst < 1)cout << -1;
  else for(int i = k - 1; i >= 0; i--){
  	cout << ans[i] << " ";
  }

}