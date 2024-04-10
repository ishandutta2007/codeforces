#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const int z=200;
int n,m;
int a[200001];
vector<int>v[201];
int pf[200001][201];
void solve(){
	cin >> n;
	for(int i=1; i<=z ;i++){
		v[i].clear();
	}
	int ans=0;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
		v[a[i]].push_back(i);
		for(int j=1; j<=z ;j++){
			pf[i][j]=pf[i-1][j];
		}
		pf[i][a[i]]++;
		ans=max(ans,pf[i][a[i]]);
	}
	for(int i=1; i<=n ;i++){
		int f=pf[i][a[i]];
		int l=i;
		int r=v[a[i]][v[a[i]].size()-f];
		//cout << l << ' ' << r << endl;
		if(r<=l) continue;
		for(int j=1; j<=z ;j++){
			ans=max(ans,pf[r-1][j]-pf[l][j]+f*2);
		}
	}
	cout << ans << '\n';
}
int main(){
	ios::sync_with_stdio(false);
	int t;cin >> t;
	while(t--){
		solve();
	}
}