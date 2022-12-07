#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define x first
#define y second
#define vi vector<int>
#define vpi vector<pii>
#define WT int TT=read();while(TT--)
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}
inline void ckmax(int &a,int b){a=(a>b?a:b);}
inline void ckmin(int &a,int b){a=(a<b?a:b);}

const int Mod=998244353;
const int M=2e5+10;
int n,a[M],dp[M];

int poww(int a,int b=Mod-2)
{
	int res=1;
	while(b)
	{ 
		if (b&1)res=res*a%Mod;
		a=a*a%Mod,b>>=1;
	}return res;
}

void solve()
{
	n=read();int cnt=0,ans=0,cnt2=0;
	for (int i=1;i<=n;i++)a[i]=read(),cnt+=a[i]==0;
	for (int i=1;i<=cnt;i++)cnt2+=a[i];
	dp[0]=0;
	for (int i=1;i<=cnt2;i++)dp[i]=(dp[i-1]+n*(n-1)/2%Mod*poww(i*i%Mod))%Mod;
	cout<<dp[cnt2]<<'\n';
}

signed main()
{
	WT solve();
	return 0;
}