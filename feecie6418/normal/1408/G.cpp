#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
vector<int> f[1505];
int fa[1505],n,m,s[1505],size[1505];
struct E{
	int x,y,z;
}e[3000005];
int gf(int x){
	return fa[x]==x?x:fa[x]=gf(fa[x]);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		fa[i]=i,size[i]=1,f[i].resize(2),f[i][1]=1;
		for(int j=1,x;j<=n;j++){
			scanf("%d",&x);
			if(i<j)e[++m]={i,j,x};
		}
	}
	sort(e+1,e+m+1,[](E i,E j){return i.z<j.z;});
	for(int i=1;i<=m;i++){
		int x=gf(e[i].x),y=gf(e[i].y);
		if(x==y){
			s[y]++;
			if(s[y]==size[y]*(size[y]-1)/2)f[y][1]=(f[y][1]+1)%mod;
			continue;
		}
		fa[x]=y,s[y]+=s[x],s[y]++,size[y]+=size[x];
		vector<int> tmp;
		tmp.resize(f[x].size()+f[y].size()-1);
		for(int j=0;j<f[x].size();j++){
			for(int k=0;k<f[y].size();k++)tmp[j+k]=(tmp[j+k]+1ll*f[x][j]*f[y][k])%mod;
		}
		f[y]=tmp;
		if(s[y]==size[y]*(size[y]-1)/2)f[y][1]=(f[y][1]+1)%mod;
	}
	for(int i=1,u=gf(1);i<=n;i++)printf("%d ",f[u][i]);
	return 0;
}