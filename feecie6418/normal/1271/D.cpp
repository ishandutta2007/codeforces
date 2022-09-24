#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[5005],b[5005],c[5005],f[5005][5005],mx[5005];
vector<int> g[5005];
int main(){
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)cin>>a[i]>>b[i]>>c[i],mx[i]=i;
	for(int i=1,x,y;i<=m;i++)cin>>x>>y,mx[y]=max(mx[y],x);
	for(int i=1;i<=n;i++)g[mx[i]].push_back(i);
	memset(f,0xc0,sizeof(f)),f[0][k]=0;
	for(int i=1;i<=n;i++){
		for(int j=a[i];j<=5000-b[i];j++)f[i][j+b[i]]=f[i-1][j];
		for(int y:g[i]){
			for(int j=1;j<=5000;j++)f[i][j-1]=max(f[i][j-1],f[i][j]+c[y]);
		}
	}
	int ans=-1e8;
	for(int i=0;i<=5000;i++)ans=max(ans,f[n][i]);
	if(ans==-1e8)cout<<"-1";
	else cout<<ans;
    return 0;
}