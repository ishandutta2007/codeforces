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
int n;
int main(){
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);cout.tie(NULL);  
  cin >> n;
  int num = 0, c = 1;
  while(num + c <= 3 * 100000){
  	num += c;
  	c *= 2;
  }
  c /= 2;
  cout << 3 << " " << 3 << ln << num << " " << n << " " << 0 << ln << c << " " << num << " " << n << ln << 0 << " " << n << " " << n;
}