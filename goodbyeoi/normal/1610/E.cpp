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

int find(int x)
{
	int tl=1,tr=n,p=n+1;
	while(tl<=tr)
	{
		int Mid=(tl+tr)>>1;
		if (a[Mid]>=x)p=Mid,tr=Mid-1;
		else tl=Mid+1;
	}return p;
}

signed main()
{
	WT
	{
		n=read();int ans=0;
		for (int i=1;i<=n;i++)a[i]=read();
		for (int i=1;i<=n;i++)
		{
			if (a[i]==a[i-1])continue;
			int now=i,sum=0;
			while(a[now]==a[i]&&now<=n)now++,sum++;
			while(now<=n)
				now=find(2*a[now]-a[i]),sum++;
			ans=max(ans,sum);
		}
		cout<<n-ans<<endl;
	}
	return 0;
}