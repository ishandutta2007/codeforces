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
#define mid ((s + e)>>1)
#define max(aa, bb) (aa > bb ? aa : bb)
#define min(aa, bb) (aa < bb ? aa : bb)
#define ln '\n'
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
ll tx, ty, sx, sy, n;
string s2;
void solve(){
	cin >> sx >> sy >> tx >> ty >> n >> s2;
	ll s = 0, e = 1e18;
	while(s < e){
		ll nx = sx, ny = sy, ch = mid/n+1;
		bool b = 1;
		for(int i = 0; i < n; i++){
			if(b && mid%n == i){b = 0;ch--;}
			if(s2[i] == 'U')ny+= ch;
			if(s2[i] == 'D')ny-= ch;
			if(s2[i] == 'L')nx-= ch;
			if(s2[i] == 'R')nx+= ch;
		}
		if(abs(nx - tx) + abs(ny - ty) > mid)s = mid + 1; 
		else e = mid;
	}
	if(e == 1e18)cout << -1;
	else cout << s;
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);cout.tie(nullptr);cerr.tie(nullptr);
  solve();
}