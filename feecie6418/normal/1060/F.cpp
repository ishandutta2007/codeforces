#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
double C[55][55],f[55][55],t[55],h[55],jc[55]={1};
vector<int> g[55];
int sz[55],n;
void dfs(int x,int fa){
	f[x][0]=1,sz[x]=1;
	for(int y:g[x]){
		if(y==fa)continue;
		dfs(y,x),memset(h,0,sizeof(h));
		for(int i=1;i<=sz[y];i++){
			for(int j=0;j<=sz[y];j++){
				if(i<=j)h[j]+=0.5*f[y][i-1]/sz[y];
				else h[j]+=f[y][j]/sz[y];
			}
		}
		for(int i=0;i<sz[x];i++){
			for(int j=0;j<=sz[y];j++){
				t[i+j]+=f[x][i]*h[j]*jc[sz[x]-1]*jc[sz[y]]/jc[sz[x]-1+sz[y]]*C[i+j][i]*C[sz[x]-i-1+sz[y]-j][sz[y]-j];
			}
		}
		sz[x]+=sz[y];
		for(int i=0;i<sz[x];i++)f[x][i]=t[i],t[i]=0;
	}
}
int main(){
	cin>>n;
	for(int i=0;i<=n;i++){
		C[i][0]=1;
		for(int j=1;j<=i;j++)C[i][j]=C[i-1][j]+C[i-1][j-1];
		if(i)jc[i]=i*jc[i-1];
	}
	for(int i=1,x,y;i<n;i++)cin>>x>>y,g[x].push_back(y),g[y].push_back(x);
	for(int i=1;i<=n;i++)dfs(i,0),printf("%.10lf\n",f[i][n-1]);
}