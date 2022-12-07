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
int n,a[M],t[M],b[M];

int check(int m)
{
	for (int i=1;i<=m;i++)if (b[i]!=b[m-i+1])return 0;return 1;
}

int del(int x)
{
	int len=0;
	for (int i=1;i<=n;i++)
		if (a[i]!=x)b[++len]=a[i];
	return check(len);
}

signed main()
{
	WT
	{
		n=read();
		for (int i=1;i<=n;i++)a[i]=read();
		int f=1;
		for (int i=1;i<=n;i++)
			if (a[i]!=a[n-i+1])
			{
				f=del(a[i])|del(a[n-i+1]);break;
			}
		if (f)YES
		else NO
	}
	return 0;
}