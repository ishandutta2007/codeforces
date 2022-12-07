//AFO countdown:11 Days
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

const int Mod=998244353;
const int M=2e5+10;
int n,a[M];

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

signed main()
{
	WT
	{
		n=read();int maxn=0,res=1;
		for (int i=1;i<=n;i++)a[i]=read(),maxn=max(maxn,a[i]),res=res*i%Mod;
		int cnt1=0,cnt2=0;
		for (int i=1;i<=n;i++)
			if (a[i]==maxn)cnt1++;
			else if (a[i]==maxn-1)cnt2++;
		if (cnt1>1)cout<<res<<endl;
		else cout<<res*cnt2%Mod*inv(1+cnt2)%Mod<<endl;
	}
	return 0;
}