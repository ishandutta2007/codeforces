#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=998244353,inv6=166374059;
int read(){
	int a=0;bool opt=0;char c=getchar();
	while(c<'0'||c>'9')opt|=c=='-',c=getchar();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=getchar();
	return opt?-a:a;
}
int Mod(int x){return x<mod?x:x-mod;}
void Add(int&x,int y){x=Mod(x+y);}
int n,ans,tmp,f[1000005],g[1000005],s[1000005];
int cal(int n){return (s[n]+1ll*s[n-1]*(s[n-1]+1)%mod*(s[n-1]+2)%mod*inv6%mod)%mod;}
int main(){
	n=read();
	f[0]=s[0]=1;
	for(int i=1;i<=n;++i){
		g[i]=(1ll*s[i-1]*(s[i-1]+1)>>1)%mod;
		f[i]=Mod(s[i-1]+g[i]+1);
		Add(f[i],mod-s[i-1]);
		Add(g[i],mod-tmp);
		s[i]=Mod(s[i-1]+f[i]);
		tmp=Mod(tmp+g[i]);
	}
	ans=2ll*Mod(cal(n)-cal(n-1)+mod)%mod;
	for(int i=1;i<n;++i)Add(ans,1ll*(f[i]-1)*g[n-i-1]%mod);
	cout<<ans-1<<"\n";
	return 0;
}