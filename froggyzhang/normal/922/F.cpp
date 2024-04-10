#include<bits/stdc++.h>
using namespace std;
#define N 300010
typedef long long ll;
int n,d[N],vis[N],p[N];
ll m;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		for(int j=i;j<=n;j+=i){
			++d[j];
		}
	}
	for(int i=1;i<=n;++i)--d[i];
	ll now=0;
	int cnt=0,t=0;
	for(int i=1;i<=n;++i){
		now+=d[i];
		++cnt,++t;
		p[i]=i;
		if(now>=m)break;
	}
	sort(p+t/2+1,p+t+1,[&](int i,int j){return d[i]<d[j];});
	for(int i=t;i>=t/2+1;--i){
		int u=p[i];
		if(now-d[u]>=m){
			now-=d[u];
			--cnt;
			vis[u]=1;
		}
	}
	if(now^m){
		cout<<"No\n";
		return 0;
	}
	cout<<"Yes\n";
	cout<<cnt<<'\n';
	for(int i=1;i<=t;++i){
		if(vis[i])continue;
		cout<<i<<' ';
	}
	return 0;
}