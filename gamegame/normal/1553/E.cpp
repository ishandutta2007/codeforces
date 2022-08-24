#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=998244353;
const int N=2e6+1;
string s,t;
int n,m;
int p[N];
int f[N];
int g[N];
int find(int x){
	if(g[x]!=x) g[x]=find(g[x]);
	return g[x];
}
bool join(int x,int y){
	x=find(x);y=find(y);
	if(x==y) return false;
	g[x]=y;
	return true;
}
void solve(){
	cin >> n >> m;
	for(int i=0; i<n ;i++) f[i]=0;
	for(int i=1; i<=n ;i++){
		cin >> p[i];
		f[(i-p[i]+n)%n]++;
	}
	vector<int>ans;
	for(int i=0; i<n ;i++){
		if(f[i]+2*m<n) continue;
		for(int j=1; j<=n ;j++) g[j]=j;
		int need=0;
		for(int j=1; j<=n ;j++){
			need+=join(j,(p[j]+i-1)%n+1);
		}
		if(need<=m) ans.push_back(i);
	}
	cout << ans.size() << ' ';
	for(auto c:ans) cout << c << ' ';
	cout << '\n';
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;while(t--) solve();
}