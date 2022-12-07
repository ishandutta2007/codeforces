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
int n,a[M],b[M],f1[M],f2[M];

int check(int x)
{
	int cnt=0;
	for (int i=1;i<=n;i++)
	{
		if (cnt<=b[i]&&(x-cnt-1)<=a[i])cnt++;
		if (cnt>=x)return 1;
	}return 0;
}

signed main()
{
	WT
	{
		n=read();
		for (int i=1;i<=n;i++)a[i]=read(),b[i]=read();
		int tl=1,tr=n,p=0;
		while(tl<=tr)
		{
			int Mid=(tl+tr)>>1;
			if (check(Mid))p=Mid,tl=Mid+1;
			else tr=Mid-1;
		}cout<<p<<endl;
	}
	return 0;
}