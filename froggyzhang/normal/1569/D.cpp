#include<bits/stdc++.h>
using namespace std;
#define N 300030
typedef long long ll;
int n,m,k,x[N],y[N];
map<int,int> cx[N],cy[N];
void Solve(){
	cin>>n>>m>>k;
	for(int i=1;i<=n;++i)cx[i].clear(),cin>>x[i];
	for(int i=1;i<=m;++i)cy[i].clear(),cin>>y[i];
	for(int i=1;i<=k;++i){
		int X,Y;
		cin>>X>>Y;
		int px=lower_bound(x+1,x+n+1,X)-x;
		int py=lower_bound(y+1,y+m+1,Y)-y;
		if(X==x[px]&&Y==y[py])continue;
		if(X==x[px])++cy[py][px];
		else ++cx[px][py];
	}
	ll ans=0;
	for(int i=1;i<=n;++i){
		int tot=0;
		for(auto [o,t]:cx[i]){
			ans-=1LL*t*(t-1)/2;
			tot+=t;
		}
		ans+=1LL*tot*(tot-1)/2;
	}
	for(int i=1;i<=m;++i){
		int tot=0;
		for(auto [o,t]:cy[i]){
			ans-=t*(t-1)/2;
			tot+=t;
		}
		ans+=1LL*tot*(tot-1)/2;
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}