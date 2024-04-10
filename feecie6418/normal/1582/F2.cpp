#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
int p1=1000000;
char buf[1000005];
int gc(){
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
const int MXA=5000,M=8192;
int n;
bitset<M+5> f[MXA+5],g[MXA+5];
bitset<MXA+5> h[M+5];
void Make(int x,int y){
	f[x][y]=1,g[x][y^x]=0,h[y][x]=0;
	if(!f[x+1][y^(x+1)])g[x+1][y]=1;
}
int main(){
	n=rd();
	for(int i=0;i<=MXA;i++){
		f[i][0]=1;
		for(int j=0;j<M;j++)if(f[i][j]&&!f[i+1][j^(i+1)])g[i+1][j]=1;
		for(int j=0;j<M;j++)if(!f[i][j])h[j][i]=1;
	}
	for(int i=1;i<=n;i++){
		int x=rd();
		if(x==0)continue;
		for(int k=g[x]._Find_first();k<M;k=g[x]._Find_next(k)){
			Make(x,k^x);
			for(int l=h[k^x]._Find_next(x);l<=MXA;l=h[k^x]._Find_next(l))Make(l,k^x);
		}
	}
	vector<int> ans;
	for(int i=0;i<M;i++)if(f[MXA][i])ans.push_back(i);
	cout<<ans.size()<<'\n';
	for(int i:ans)cout<<i<<' ';
}