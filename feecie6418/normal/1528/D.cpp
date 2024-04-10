#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dis[605],g[605][605],a[605];
int n,m,vst[605];
void Do(int s){
	memset(dis,0x3f,sizeof(dis)),memset(vst,0,sizeof(vst)),dis[s]=0;
	for(int i=0;i<n;i++){
		ll mn=1e18,p=0;
		for(int j=0;j<n;j++)if(!vst[j]&&dis[j]<mn)mn=dis[j],p=j;
		vst[p]=1;
		for(int j=0;j<n;j++)a[(j+dis[p])%n]=g[p][j]+dis[p];
		ll w=1e18;
		for(int j=0;j<n;j++)w=min(w,a[j]-j),dis[j]=min(dis[j],w+j);
		w=1e18;
		for(int j=n-1;j>=0;j--)w=min(w,a[j]-j),dis[j]=min(dis[j],w+j+n);
	}
	for(int i=0;i<n;i++)cout<<dis[i]<<' ';
	puts("");
}
int main(){
	cin>>n>>m,memset(g,0x3f,sizeof(g));
	for(int i=1,x,y,z;i<=m;i++)scanf("%d%d%d",&x,&y,&z),g[x][y]=z;
	for(int i=0;i<n;i++)Do(i);
}