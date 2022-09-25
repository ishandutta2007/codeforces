#include<bits/stdc++.h>
using namespace std;
#define N 1000100
typedef long long ll;
int n,m,a[N],b[N],g;
ll Solve(int op){
	ll tot=0;
	for(int t=1;t<=g;++t){
		int zz=0,mn=2e9;
		ll all=0;
		for(int i=t;i<=n;i+=g){
			if(a[i]<0)zz^=1;
			all+=abs(a[i]);
			mn=min(mn,abs(a[i]));
		}
		if(zz^op)all-=2LL*mn;
		tot+=all;
	}
	return tot;
}
void Solve(){
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	g=0;
	for(int i=1;i<=m;++i){
		cin>>b[i];
		g=__gcd(g,b[i]);
	}
	cout<<max(Solve(0),Solve(1))<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}