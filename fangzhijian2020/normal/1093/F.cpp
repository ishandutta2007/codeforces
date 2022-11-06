#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=998244353;
int read(){
	int a=0;bool opt=0;char c=getchar();
	while(c<'0'||c>'9')opt|=c=='-',c=getchar();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=getchar();
	return opt?-a:a;
}
int n,K,len,x,a[100005],f[100005][105],g[100005],opt[105],sum,t;
int Mod(int x){return x<mod?x:x-mod;}
void Add(int&x,int y){x=Mod(x+y);}
int main(){
	n=read();K=read();len=read();
	g[0]=1;
	for(int i=1;i<=n;++i){
		x=read();a[i]=x;
		if(x!=-1){if(!opt[x])++sum;++opt[x];t=x;}
		if(a[i-len]!=-1){--opt[a[i-len]];
			if(!opt[a[i-len]])--sum;
		}
		
		if(x==-1){
			for(int j=1;j<=K;++j){
				f[i][j]=g[i-1];
				if(i>=len&&!sum)Add(f[i][j],Mod(mod-g[i-len]+f[i-len][j]));
				if(i>=len&&sum==1&&t==j)Add(f[i][j],Mod(mod-g[i-len]+f[i-len][j]));
			}
		}
		else{
			f[i][x]=g[i-1];
			if(i>=len&&!sum)Add(f[i][x],Mod(mod-g[i-len]+f[i-len][x]));
			if(i>=len&&sum==1&&t==x)Add(f[i][x],Mod(mod-g[i-len]+f[i-len][x]));
		}
		for(int j=1;j<=K;++j)Add(g[i],f[i][j]);
//		if(g[i]==0){puts("0");return 0;}
	}
	cout<<g[n];
	return 0;
}