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

const int M=3e5+10;
int n,m,a[M];

signed main()
{
	n=read(),m=read();int ans=n;
	for (int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		if (u<v)swap(u,v);
		a[v]++;if (a[v]==1)ans--;
	}
	int q=read();
	while(q--)
	{
		int opt=read();
		if (opt==3)cout<<ans<<endl;
		else if (opt==1)
		{
			int u=read(),v=read();
			if (u<v)swap(u,v);
			a[v]++;if (a[v]==1)ans--;
		}
		else
		{
			int u=read(),v=read();
			if (u<v)swap(u,v);
			a[v]--;if (a[v]==0)ans++;
		}
	}
	return 0;
}