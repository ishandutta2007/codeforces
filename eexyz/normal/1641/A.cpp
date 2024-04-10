#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1000005
#define int long long
int n,m,T,a[N],j,fl,gg,X,i,x[N],vis[N];
signed main(){
	ios::sync_with_stdio(0);
	cin>>T;
	while(T--){
		cin>>n>>X;
		for(i=1;i<=n;++i)vis[i]=0,cin>>x[i];
		sort(x+1,x+n+1);fl=0;
		for(j=i=1;i<=n;++i){
			if(vis[i])continue;
			gg=X*x[i];
			while(j<=n&&x[j]<gg)++j;
			if(j<=n&&x[j]==gg)++fl,vis[j]=1,++j;
		}
		cout<<n-fl*2<<"\n";
	}
}