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
int t, n, k;
string s;
int main(){
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);cout.tie(NULL);  
  cin >> t;
  while(t--){
  	cin >> n >> k >> s;
  	int ct[k + 1][500], arr[k + 1];
  	memset(arr, 0, sizeof arr);
  	memset(ct, 0, sizeof ct);
  	for(int i = 0; i < n; i++){
  		if(i % k >= (int)ceil((double)k / 2))continue;
  		//cerr << i << " ";
  		arr[i % k] = max(arr[i % k], ++ct[i % k][s[i]]);
  	} 	
  	reverse(all(s));
  	for(int i = 0; i < n; i++){
  		if(i % k >= (int)ceil((double)k / 2))continue;
  		arr[i % k] = max(arr[i % k], ++ct[i % k][s[i]]);
  	} 	
  	int ans = n;
  	if(k % 2)arr[k / 2]/=2;
  	for(int i = 0; i < k; i++){
  		ans -=arr[i];
  	}
  	cout << ans << ln;
  	//cerr << ln;
  }
}