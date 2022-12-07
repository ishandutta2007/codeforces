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

const int Mod=1e9+7;
const int M=3e6+10;
int n,q,inv[M],fac[M],ifac[M],ans[M],f[M];

void init(int n)
{
	inv[1]=fac[0]=fac[1]=ifac[0]=ifac[1]=1;
	for (int i=2;i<=n;i++)
	{
		inv[i]=(Mod-Mod/i)*inv[Mod%i]%Mod;
		fac[i]=fac[i-1]*i%Mod;
		ifac[i]=ifac[i-1]*inv[i]%Mod;
	}
}

int C(int m,int n){return fac[m]*ifac[n]%Mod*ifac[m-n]%Mod;}

signed main()
{
	n=read(),q=read();
	init(3*n+3);
	for (int i=0;i<3*n+3;i++)ans[i]=C(3*n+3,i+1);
	ans[0]=(ans[0]-3+Mod)%Mod,ans[1]=(ans[1]-3+Mod)%Mod,ans[2]=(ans[2]-1+Mod)%Mod;
	for (int i=3*n+2;i>=2;i--)
	{
		f[i-2]=ans[i];
		ans[i]-=f[i-2],ans[i-1]-=f[i-2]*3,ans[i-2]-=f[i-2]*3;
		ans[i-1]=(ans[i-1]%Mod+Mod)%Mod,
		ans[i-2]=(ans[i-2]%Mod+Mod)%Mod;
	}
	while(q--)
	{
		int x=read();
		cout<<f[x]<<endl;
	}
	return 0;
}