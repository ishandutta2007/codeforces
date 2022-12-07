#pragma GCC optimize(2)
#pragma GCC optimize(3)
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
const int M=1e5+10;
int n,a[M],sum[M],la[M],p[M];

signed main()
{
	WT
	{
		n=read();int ans=0;
		for (int i=1;i<=n;i++)a[i]=read();
		int now=a[n],sum=0;
		for (int i=n-1;i>=1;i--)
		{
			la[i]=now=min(now,a[i]);
			int k=(a[i]-1)/now,val=a[i]/(k+1);
			sum+=k*i;p[i]=k;now=val;
		}ans=sum%Mod;//cout<<sum<<endl;
		for (int i=n-1;i>=1;i--)
		{
			sum-=i*p[i];int now=a[i];
			for (int j=i-1;j>=1;j--)
			{
				int X=la[j];la[j]=now=min(now,a[j]);
				int k=(a[j]-1)/now,val=a[j]/(k+1);
				sum+=k*j-p[j]*j;p[j]=k;now=val;
				if (la[j]==X)break;
			}
			ans=(ans+sum)%Mod;
		}printf("%lld\n",ans);
	}
	return 0;
}
/*
4
3
5 4 3
4
3 2 1 4
1
69
8
7264 40515 28226 92776 35285 21709 75124 48163
*/