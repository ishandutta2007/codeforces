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

const int M=110;
string s;

signed main()
{
	WT
	{
		int n=read(),a=read(),b=read();
		cin>>s;
		if (b>=0)
			cout<<n*(a+b)<<endl;
		else
		{
			int res=1;
			for (int i=2;i<=n;i++)
				if (s[i-1]!=s[i-2])res++;
			cout<<n*a+(res/2+1)*b<<endl;
		}
	}
	return 0;
}