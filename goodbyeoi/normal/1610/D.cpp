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
const int M=2e5+10;
int n,a[M],res;

int poww(int a,int b)
{
	int res=1;
	while(b)
	{
		if (b&1)res=res*a%Mod;
		a=a*a%Mod,b>>=1;
	}return res;
}

signed main()
{
	n=read();int res=0,cnt=0;
	for (int i=1;i<=n;i++)
		a[i]=read(),cnt+=a[i]&1;
	for (int now=2;now<=1e9;now*=2)
	{
		int cnt1=0,cnt2=0;
		for (int i=1;i<=n;i++)
			if (a[i]%now==0)
			{
				if (a[i]%(now*2)==0)cnt2++;
				else cnt1++;
			}
		if (cnt1+cnt2==0)break;
		if (cnt1==0)continue;
		res+=(poww(2,cnt1-1)-1)*poww(2,cnt2)%Mod;
//		cout<<res<<' ';
	}res=(res+poww(2,n-cnt)*(poww(2,cnt)-1))%Mod;
	cout<<res<<endl;
	return 0;
}