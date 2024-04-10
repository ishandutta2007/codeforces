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

const int M=1e5+10;
int n,a[M];

int lcm(int x,int y)
{
	if (x==-1)return -1;
	int d=__gcd(x,y);
	return x*y/d;
}

signed main()
{
	WT
	{
		n=read();int p=1,f=1;
		for (int i=1;i<=n;i++)
		{
			a[i]=read();p=lcm(p,i+1);int p=1;
			for (int j=2;j<=40&&j<=i+1;j++)
				if (a[i]%j!=0)p=0;
			if (p)f=0;
		}
		if (f)YES
		else NO
	}
	return 0;
}