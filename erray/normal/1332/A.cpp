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
int t, a, b, c, d, x, y, rx, ry, lx, ly;
int main(){
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);cout.tie(NULL);  
  cin >> t;
  while(t--){
  	cin >> a >> b >> c >> d >> x >> y >> lx >> ly >> rx >> ry;
  	int ab = b - a, cd = d - c;
  	bool b = 1;
  	if((ab == 0 && a != 0 && lx == rx) || (cd == 0 && c != 0 && ly == ry))b = 0; 
  	cout << (b && x + ab >= lx && x + ab <= rx && y + cd >= ly && y + cd <= ry && b ? "Yes" : "No" ) << ln;
  }
}