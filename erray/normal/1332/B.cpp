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
int t, n, x;
vi pr;
bool isPrime[1005];
int main(){
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);cout.tie(NULL); 
  for(int i = 2; i <= 1000; i++){
  	if(!isPrime[i]){
  		//cerr << i << ln;
  		pr.pb(i);
  		for(int j = i * 2; j <= 1000; j+= i)isPrime[j] = 1;
  	}
  } 
  cin >> t;
  while(t--){
  	cin >> n;
  	vi v;
  	int ans[n + 1];
  	memset(ans, 0, sizeof ans);
  	for(int i = 0; i < n; i++){cin >> x;v.pb(x);}
  	int col = 1;
  	for(auto a : pr){
  		bool b = 0;
  		int ind = 0;
  		for(auto a2 : v){
  			if(a2 % a == 0 && ans[ind] == 0){
  				b = 1;
  				ans[ind] = col;
  			}	
  			ind++;
  			//cerr << ind << ln;
  		}
  		col += b;
  	}		
  	cout << col - 1 << ln;
  	for(int i = 0; i< n ;i++){
  		cout << ans[i] << " ";
  	}
  	cout << ln;
  }
}