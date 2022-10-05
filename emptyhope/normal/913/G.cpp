#include<bits/stdc++.h>
#define For(i,a,b) for(register int i=(a);i<=(b);++i)
#define Rep(i,a,b) for(register int i=(a);i>=(b);--i)
#define int long long 
using namespace std;
inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

inline int mul(int x,int y,int mod){
	int res=0;
	while(y){
		if(y&1)res=(res+x)%mod;
		y>>=1,x=(x<<1)%mod;
	}return res;
}
inline int qpow(int x,int y,int mod){
	int res=1;
	while(y){
		if(y&1)res=mul(res,x,mod);
		y>>=1,x=mul(x,x,mod);
	}return res;
}

void work()
{
	int a=read(),qwq=a,n=0;
	while(qwq)++n,qwq/=10;
	for(int pw=10,m=1;;m++,pw*=10)
	{
		int mod=(1ll<<(n+m));
		if(pw<mod) continue;
		int b=(-a*pw%mod+mod)%mod;
		if(b%5==0) b+=mod;
		if(b>=pw)continue;
		int x=(a*pw+b)/mod;
		int phi=4,pw5=25,res;
		For(i,0,4)
			if(qpow(2,i,5)==x%5){res=i;break;}
	//	cout<<"res "<<res<<" "<<x<<endl;
		for(int i=2;i<=n+m;++i,phi*=5,pw5*=5){
			For(j,0,4)
				if(qpow(2,res+phi*j,pw5)==x%pw5){
					res+=phi*j;
					break;
				}
		}
		res+=m+n;
		cout<<res<<endl;
		return;
	}
}

signed main()
{
	int T=read();
	while(T--)work();
	return 0;
}