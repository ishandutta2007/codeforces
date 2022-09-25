#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 303
int T,k,n,m,a[N],b[N];
void Solve(){
	cin>>k>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=1;i<=m;++i)cin>>b[i];
	a[n+1]=b[m+1]=1e9+233;
	vector<int> ans;
	int i=1,j=1;
	while(i<=n||j<=m){
		if(a[i]>k&&b[j]>k){
			cout<<-1<<'\n';
			return;
		}
		while(a[i]<=k)k+=a[i]==0,ans.push_back(a[i++]);
		while(b[j]<=k)k+=b[j]==0,ans.push_back(b[j++]);
	}
	for(auto x:ans)cout<<x<<' ';
	cout<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--)Solve();
	return 0;
}