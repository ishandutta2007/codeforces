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
int n,a[M];

bool check(int l,int r)
{
	for (int i=l;i<=r;i++)
		for (int j=i+1;j<=r;j++)
			for (int k=j+1;k<=r;k++)
				if ((a[i]>=a[j]&&a[j]>=a[k])||(a[i]<=a[j]&&a[j]<=a[k]))return 0;
	return 1;
}

signed main()
{
	WT
	{
		n=read();int ans=0;
		for (int i=1;i<=n;i++)
			a[i]=read();
		for (int i=1;i<=n;i++)
			for (int j=i;j<=n&&j<=i+4;j++)
				if (check(i,j))ans++;
		cout<<ans<<endl;
	}
	return 0;
}