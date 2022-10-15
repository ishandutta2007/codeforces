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
#define ln '\n'
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int t, n, x;
void solve(){
	cin >> n;
	int ans = -1;
	vi v, pl[205];
	int ct[205]; 
	for(int i = 0; i < n; i++){cin >> x;v.pb(x);pl[x].pb(i);}
	for(int j = 1; j <= 200; j++){
		memset(ct, 0, sizeof ct);
		int mx = 0;
		if(pl[j].size() < 2)continue;
		int s, e;
		if(pl[j].size()&1)s = pl[j].size()/2 - 1, e = pl[j].size() - pl[j].size()/2;
		else s = pl[j].size()/2 - 1, e =  pl[j].size()/2;
		for(int i = pl[j][s] + 1; i < pl[j][e]; i++)mx = max(++ct[v[i]], mx);
		while(s!=-1){
			ans = max((s+1)*2 + mx, ans);
			if(s==0)break;
			for(int i = pl[j][s]; i > pl[j][s - 1]; i--)mx = max(++ct[v[i]], mx);
			for(int i = pl[j][e]; i < pl[j][e + 1]; i++)mx = max(++ct[v[i]], mx);
			s--;
			e++;
		}
	}
	cout << max(ans, 1) << ln;
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);cout.tie(nullptr);cerr.tie(nullptr);
  cin >> t;
  while(t--)solve();
}