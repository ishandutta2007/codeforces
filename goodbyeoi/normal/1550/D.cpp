#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define WT int TT=read();while(TT--)
#define NO puts("NO");
#define YES puts("YES");
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int M=2e5+10;
const int Mod=1e9+7;
int n,fac[M],ifac[M];
map<int,int>t;
int poww(int a,int b)
{
	int res=1;
	while(b)
	{
		if (b&1)res=res*a%Mod;
		a=a*a%Mod,b>>=1;
	}return res;
}
int inv(int x){return poww(x,Mod-2);}
void init(int n)
{
	fac[0]=ifac[0]=1;
	for (int i=1;i<=n;i++)
		fac[i]=fac[i-1]*i%Mod,
		ifac[i]=inv(fac[i]);
}
int C(int m,int n){return fac[m]*ifac[n]%Mod*ifac[m-n]%Mod;}

signed main()
{
	init(2e5);
	WT
	{
		t.clear();
		int n=read(),l=read(),r=read();
		int cnt=min(1-l,r-n)*2;//cout<<cnt<<endl;
		int ans=cnt*C(n,n/2)%Mod;
		for (int i=2-l;;i++)
		{
			if (t[i])continue;t[i]=1;
			int f1=n/2,f2=n-n/2;
			f2-=l+i-1,f1-=max(0ll,n-r+i);
			if (f1<0||f2<0)break;
			ans+=C(f1+f2,f2);ans%=Mod;
		}
		for (int i=r-n+1;;i++)
		{
			if (t[i])continue;t[i]=1;
			int f1=n/2,f2=n-n/2;
			f1-=n-r+i,f2-=max(0ll,l+i-1);
			if (f1<0||f2<0)break;
			ans=ans+C(f1+f2,f1);ans%=Mod;
		}
		for (int i=n-r-1;;i--)
		{
			if (t[i])continue;t[i]=1;
			int f1=n/2,f2=n-n/2;
			f2-=n-r-i,f1-=max(0ll,l-i-1);
			if (f1<0||f2<0)break;
			ans=ans+C(f1+f2,f1);ans%=Mod;
		}
		for (int i=l-2;;i--)
		{
			if (t[i])continue;t[i]=1;
			int f1=n/2,f2=n-n/2;
			f1-=l-i-1,f2-=max(0ll,n-r-i);
			if (f1<0||f2<0)break;
			ans+=C(f1+f2,f2);ans%=Mod;
		}
		if (n%2==0)ans=ans*inv(2)%Mod;
		cout<<ans<<endl;
	}
	return 0;
}
/*
1
4 -3 5

*/