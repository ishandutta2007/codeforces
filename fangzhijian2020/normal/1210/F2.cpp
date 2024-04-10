#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<bitset>
#include<unordered_map>
using namespace std;
const int mod=1e9+7,inv=570000004;
int read(){
	int a=0;bool opt=0;char c=getchar();
	while(c<'0'||c>'9')opt|=c=='-',c=getchar();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=getchar();
	return opt?-a:a;
}
int n,p1[10][10],p2[10][10],tot,dp[10][65000],p[128],trans[65000][128];
int Mod(int x){return x<mod?x:x-mod;}
void Add(int&x,int y){x=Mod(x+y);}
bitset<128>I;unordered_map<bitset<128>,int>a;
int dfs(bitset<128> I){
	if(a.find(I)!=a.end())return a[I];
	a[I]=++tot;bitset<128>A[10],tmp;
	for(int i=0;i<n;++i){
		for(int j=0;j<(1<<n);++j){
			A[i][j|(1<<i)]=A[i][j|1<<i]|I[j];
		}
	}
	for(int i=0;i<(1<<n);++i){
		tmp=I;
		for(int j=0;j<n;++j){
			if((i>>j)&1)tmp|=A[j];	
		}
		trans[a[I]][i]=dfs(tmp);
	}
	return a[I];
}
int main(){
//	freopen("nagi.in","r",stdin);
//	freopen("nagi.out","w",stdout);
	n=read();I[0]=1;dfs(I);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			p1[i][j]=1ll*read()*inv%mod;
			p2[i][j]=Mod(1-p1[i][j]+mod);
		}
	}
	dp[0][1]=1;
	for(int i=0;i<n;++i){
		for(int k=0;k<(1<<n);++k){
			p[k]=1;
			for(int j=1;j<=n;++j){
				if((k>>j-1)&1)p[k]=1ll*p[k]*p1[i+1][j]%mod;
				else p[k]=1ll*p[k]*p2[i+1][j]%mod;
			}
		}
		for(int j=1;j<=tot;++j){
			for(int k=0;k<(1<<n);++k){
				int Next=trans[j][k];
				Add(dp[i+1][Next],1ll*dp[i][j]*p[k]%mod);
			}
		}
	}
	for(int i=0;i<(1<<n);++i)I[i]=1;printf("%d\n",dp[n][a[I]]);
	return 0;
}