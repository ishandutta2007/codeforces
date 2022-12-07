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

const int Mod=1e9+7;
int ans,n,now;

int lcm(int a,int b)
{
	int d=__gcd(a,b);
	if (a/d*b>n)return -1;
	return a/d*b;
}

signed main()
{
	WT
	{
		n=read(),ans=n%Mod,now=1;
		for (int i=1;i<=100;i++)
		{
			now=lcm(now,i);
			if (now==-1)break;
			ans=(ans+n/now)%Mod;
		}cout<<ans<<endl;
	}
	return 0;
}