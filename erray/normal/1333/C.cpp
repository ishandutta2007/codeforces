#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h> 
#define pb emplace_back
#define mp make_pair 
#define st first 
#define nd second 
#define all(v) v.begin(),v.end()
#define umap unordered_map
#define L nd<<1
#define R (L)|1
#define mid (s + e)/2
#define ln '\n'
#define MAX (ll)(1<<30)
#define MOD 1000000007
#define mod 998244353
#define N 500005
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll; 
int n, x, lst = -1;
ll ans, sum;
map <ll, int> pos; 
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);cout.tie(NULL);
  cin >> n;
  pos[0] = 0;
  for(int i = 0; i < n; i++){
  	cin >> x;
  	sum+=x;
  	if(pos.find(sum)!=pos.end())lst = max(lst, pos[sum]);
  	pos[sum] = i + 1;
  	ans += i - lst;
  	//cerr << lst << " ";
  }
  cout << ans;
}