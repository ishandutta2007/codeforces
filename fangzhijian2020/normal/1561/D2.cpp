#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int read(){
	int a=0;bool opt=0;char c=getchar();
	while(c<'0'||c>'9')opt|=c=='-',c=getchar();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=getchar();
	return opt?-a:a;
}
int n,mod,f[4000005],s[4000005];
int main(){
	n=read();mod=read();
	f[n]=s[n]=1;
	for(int i=n-1;i;--i){
		f[i]=s[i+1];
		for(int j=2;i*j<=n;++j){
			f[i]=((f[i]+s[i*j])%mod-s[min(n+1,(i+1)*j)]+mod)%mod;
		}
		s[i]=(s[i+1]+f[i])%mod;
	}
	cout<<f[1]<<"\n";
	return 0;
}