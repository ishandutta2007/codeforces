#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ui unsigned int
#define ull unsigned long long
using namespace std;
int read(){
	int a=0;bool opt=0;char c=getchar();
	while(c<'0'||c>'9')opt|=c=='-',c=getchar();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=getchar();
	return opt?-a:a;
}
struct Fast_Mod {
	ui M,a,b;
	inline Fast_Mod(const ui m=2):M(m),a((1ull<<32)/m),b(((1ull<<32)%m<<32)/m){}
	inline ull Mo(ull x) const {
		return x-=((((x&~0u)*a+(x>>32)*b)>>32)+(x>>32)*a)*M,x>=M?x-M:x;
	} 
}F;
int n,m,k,mod,c[105][105],f[105][105][105];
int Mod(int x){return x<mod?x:x-mod;}
void Add(int&x,int y){x=Mod(x+y);}
int solve(int n,int m,int k){
	k=max(0,k);
	if(!n)return (m==0);
	if(f[n][m][k]!=-1)return f[n][m][k];
	int ret=0;if(k==1)--m;
	for(int i=1;i<=n;++i){
		for(int j=max(0,m+i-n);j<=min(i-1,m);++j){
			Add(ret,F.Mo(F.Mo(1ll*solve(i-1,j,k-1)*solve(n-i,m-j,k-1))*c[n-1][i-1]));
		}
	}
	if(k==1)++m;
	return f[n][m][k]=ret;
}
int main(){
	n=read();m=read();k=read();mod=read();
	F=Fast_Mod(mod);
	c[0][0]=1;
	for(int i=1;i<=n;++i){
		c[i][0]=1;
		for(int j=1;j<=n;++j){
			c[i][j]=F.Mo(c[i-1][j]+c[i-1][j-1]);
		}
	}
	memset(f,-1,sizeof(f));cout<<solve(n,k,m)<<"\n";
	return 0;
}