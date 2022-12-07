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

const int M=55;
int n,Mod,dp1[M][M*M],sum[M][M*M],f[M];

signed main()
{
	n=read(),Mod=read();
	dp1[1][0]=1;
	for (int i=1;i<n;i++)
		for (int j=0;j<=i*(i-1)/2;j++)
			for (int k=1;k<=i+1;k++)
				dp1[i+1][j+k-1]=(dp1[i+1][j+k-1]+dp1[i][j])%Mod;
	for (int i=1;i<=n;i++)
		for (int j=0;j<=i*(i-1)/2;j++)
			sum[i][j]=(dp1[i][j]+sum[i][j==0?0:j-1])%Mod;
	for (int i=1;i<=n;i++)
	{
		f[i]=i*f[i-1]%Mod;
		for (int j=1;j<=i;j++)
			for (int k=j+1;k<=i;k++)
				for (int p1=k-j+1;p1<=(i-1)*(i-2)/2;p1++)
					f[i]=(f[i]+dp1[i-1][p1]*sum[i-1][p1+j-k-1])%Mod;
	}
	cout<<f[n]<<endl;
	return 0;
}