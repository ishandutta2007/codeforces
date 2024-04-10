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

signed main()
{
	WT
	{
		int n=read(),ans=0,res=n,p=1;
		for (int i=1;i<=n;i++)
		{
			if (res==0)break;
			if (res<p){ans++;break;}
			res-=p;
			p+=2;++ans;
		}cout<<ans<<endl;
	}
	return 0;
}