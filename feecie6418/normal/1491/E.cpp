#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define size SZ
typedef long long ll;
int p1=1000000;
char buf[1000005];
int gc(){
	//return getchar();
	if(p1>=1000000)fread(buf,1,1000000,stdin),p1=0;
	return buf[p1++];
}
int rd(){
	int x=0;
	char ch=gc();
	while(ch<'0'||ch>'9')ch=gc();
	while(ch<='9'&&ch>='0')x=x*10+ch-'0',ch=gc();
	return x;
}
int n,f[45]={1,1},size[200005],F[200005],s1,s2,vst1[200005],vst2[200005],dfn[200005],sign;
vector<vector<int> > g;
void dfs(int x,int fa){
	size[x]=1,F[x]=fa,dfn[x]=++sign;
	for(int y:g[x])if(y!=fa)dfs(y,x),size[x]+=size[y];
}
bool Judge(int n,vector<vector<int> > tmp){
	if(n==1||n==2||n==3)return 1;
	int pos=-1;
	for(int i=0;i<=40;i++)if(f[i]==n){pos=i;break;}
	if(pos==-1)return 0;
	sign=0,g=tmp,dfs(1,0);
	for(int i=1;i<=n;i++){
		if(size[i]==f[pos-1]||n-size[i]==f[pos-1]){
			s1=s2=0;
			//dfs2(i,F[i]),dfs3(F[i],i);
			for(int j=1;j<=n;j++)if(dfn[j]>=dfn[i]&&dfn[j]<dfn[i]+size[i])vst1[j]=++s1;else vst2[j]=++s2;
			vector<vector<int> > g1,g2;
			g1.resize(size[i]+1),g2.resize(n-size[i]+1);
			for(int j=1;j<=n;j++){
				for(int k:g[j]){
					if(vst1[j]&&vst1[k])g1[vst1[j]].push_back(vst1[k]);
					if(vst2[j]&&vst2[k])g2[vst2[j]].push_back(vst2[k]);
				}
			}
			for(int j=1;j<=n;j++)vst1[j]=vst2[j]=0;
			int x=size[i],y=n-size[i];
			bool ret=Judge(x,g1)&&Judge(y,g2);
			return ret;
		}
	}
	return 0;
}
int main(){
	for(int i=2;i<=40;i++)f[i]=f[i-1]+f[i-2];
	n=rd();
	vector<vector<int> > g;
	g.resize(n+1);
	for(int i=1,x,y;i<n;i++)x=rd(),y=rd(),g[x].push_back(y),g[y].push_back(x);
	if(Judge(n,g))puts("Yes");
	else puts("No");
}