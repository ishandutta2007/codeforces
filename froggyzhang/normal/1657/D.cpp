#include<bits/stdc++.h>
using namespace std;
#define N 1000100
typedef long long ll;
int n,m,Q;
ll c[N],g[N];
inline void ckmax(ll &a,ll b){a=max(a,b);}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		int a,x,y;
		cin>>a>>x>>y;
		c[a]=max(c[a],1LL*x*y);
	}
	for(int i=1;i<=m;++i)
		for(int j=1;i*j<=m;++j)
			ckmax(g[i*j],j*c[i]);
	for(int i=1;i<=m;++i)
		g[i]=max(g[i],g[i-1]);
	cin>>Q;
	for(int i=1;i<=Q;++i){
		ll x,y;
		cin>>x>>y;
		x*=y;
		if(x>=g[m]){
			cout<<-1<<' ';
		}
		else{
			cout<<upper_bound(g+1,g+m+1,x)-g<<' ';
		}
	}
	return 0;
}