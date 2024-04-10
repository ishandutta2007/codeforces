
// Problem : D. 505
// Contest : Codeforces - Codeforces Round #663 (Div. 2)
// URL : https://codeforces.com/contest/1391/problem/D
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

/*
 A Submission by $%U%$
 at time: $%Y%$-$%M%$-$%D%$ $%h%$:$%m%$:$%s%$
*/
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define fef(i,a,b) for(ll i=a;i<=b;i++)
#define rer(i,a,b) for(ll i=b;i>=a;i--)
#define wew while(true)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define FILE_IN "cseq.inp"
#define FILE_OUT "cseq.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
#define ord(a,b,c) ((a>=b)and(b>=c))
#define MOD (ll(1000000007))
#define MAX 300001
#define mag 320
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pow2(x) (ll(1)<<x)
#define pii pair<int,int>
#define piii pair<int,pii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
typedef long long ll;
//---------END-------//
int n,m,k,c[501],pos[100001],t,t1,i,j;
int dp[1000001][8];
int mp[1000001][4];
int good(int mask0, int mask1)
{
		int cnt=0;
	for (int i=0;i+1<m;i++)
	{
		cnt=0;
		cnt+=(mask0>>i)%2;
		cnt+=(mask1>>i)%2;
		cnt+=(mask0>>(i+1))%2;
		cnt+=(mask1>>(i+1))%2;
		if (cnt%2==0) return 0;
	}
	return 1;
}
int main()
{
	char cc;
//  ofile;
    fio;
    cin>>n>>m;
    if ((n>=4)and(m>=4)) return cout<<-1,0;
    if (n<=3)
    {
    	for (i=1;i<=n;i++) for (j=1;j<=m;j++) cin>>cc,mp[j][i]=cc-48;
    	k=n;
    	n=m;
    	m=k;
    }
    else
    {
    	for (i=1;i<=n;i++) for (j=1;j<=m;j++) cin>>cc,mp[j][i]=cc-48;
    }
    for (i=n;i>=1;i--) for (j=0;j<8;j++)
    {
    	dp[i][j]=1e9;
    	if (i==n) dp[i][j]=0;
    	else
    	{
    	for (k=0;k<8;k++)
    	{
    		if (good(j,k)) dp[i][j]=min(dp[i][j],dp[i+1][k]);
    	}
    	}
    	for (k=0;k<m;k++) dp[i][j]+=abs((j>>k)%2-mp[i][k+1]);
  //  	cout<<i<<' '<<j<<' '<<dp[i][j]<<endl;
    }
    int res=1e9;
    for (i=0;i<8;i++) res=min(res,dp[1][i]);
    if (res==1e9) cout<<-1; else cout<<res;
}