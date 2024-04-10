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
int n,a[M],ans[M];

signed main()
{
	WT
	{
		n=read();
		for (int i=1;i<=n;i++)a[i]=read();
		sort(a+1,a+1+n);int d=0;
//		for (int i=1;i<=n;i++)ans[i]=0;
		for (int j=0;j<=30;j++)
		{
			int sum=0;
			for (int i=1;i<=n;i++)
				if ((a[i]>>j)&1)sum++;
			if (sum==0)continue;
			d=__gcd(d,sum);
		}
		for (int i=1;i<=n;i++)
			if (d%i==0)cout<<i<<' ';puts("");
	}
	return 0;
}