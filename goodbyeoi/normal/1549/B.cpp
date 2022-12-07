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
int n,m,a[M],b[M];
string s1,s2;

signed main()
{
	WT
	{
		cin>>n>>s1>>s2;int ans=0;
		for (int i=1;i<=n;i++)a[i]=s1[i-1]-'0',b[i]=s2[i-1]-'0';
		for (int i=1;i<=n;i++)
		{
			if (a[i]==0)
			{
				if (b[i]==1)
					ans++,b[i]=0;
			}
			else
			{
				if (b[i-1]==1)b[i-1]=0,ans++;
				else if (b[i+1]==1)b[i+1]=0,ans++;
			}
		}cout<<ans<<endl;
		for (int i=1;i<=n;i++)a[i]=b[i]=0;
	}
	return 0;
}