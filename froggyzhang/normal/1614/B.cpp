#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 200020
int n,a[N],p[N],pos[N];
void Solve(){
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		p[i]=i;
	}
	ll ans=0;
	sort(p+1,p+n+1,[&](int i,int j){return a[i]>a[j];});
	int l=0,r=0;
	for(int i=1;i<=n;++i){
		int u=p[i];
		if(i&1)pos[u]=--l;
		else pos[u]=++r;
		ans+=2LL*abs(pos[u])*a[u];
	}
	cout<<ans<<'\n';
	for(int i=0;i<=n;++i){
		cout<<pos[i]<<' ';
	}
	cout<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}