#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define WT int TT=read();while(TT--) 
#define NO puts("No");
#define YES puts("Yes");
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
		int n=read(),a=read(),b=read();
		if (a==1)
		{
			if (n%b==1||b==1)YES
			else NO
			continue;
		}int now=1,f=0;
		while(now<=n)
		{
			if ((n-now)%b==0){f=1;break;}
			now*=a;
		}if (f)YES
		else NO
	}
	return 0;
}