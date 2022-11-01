
// Problem : D. Rarity and New Dress
// Contest : Codeforces - Codeforces Round #662 (Div. 2)
// URL : https://codeforces.com/contest/1393/problem/D
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
int n,m,k,pos[100001],t,t1,i,j;
char c[2001][2001];
int lu[2001][2001],ld[2001][2001],ru[2001][2001],rd[2001][2001];
int main()
{
//  ofile;
    fio;
    cin>>n>>m;
    for (i=1;i<=n;i++) for (j=1;j<=m;j++) cin>>c[i][j];
    for (i=1;i<=n;i++) for (j=1;j<=m;j++)
    {
    	if ((i>1)and(j>1)and(c[i-1][j]==c[i][j])and(c[i][j-1]==c[i][j])) lu[i][j]=min(lu[i-1][j],lu[i][j-1])+1;
    	else lu[i][j]=1;
    }
    for (i=1;i<=n;i++) for (j=m;j>=1;j--)
    {
    	if ((i>1)and(j<m)and(c[i-1][j]==c[i][j])and(c[i][j+1]==c[i][j])) ru[i][j]=min(ru[i-1][j],ru[i][j+1])+1;
    	else ru[i][j]=1;
    }
    for (i=n;i>=1;i--) for (j=1;j<=m;j++)
    {
    	if ((i<n)and(j>1)and(c[i+1][j]==c[i][j])and(c[i][j-1]==c[i][j])) ld[i][j]=min(ld[i+1][j],ld[i][j-1])+1;
    	else ld[i][j]=1;
    }
   for (i=n;i>=1;i--) for (j=m;j>=1;j--)
    {
    	if ((i<n)and(j<m)and(c[i+1][j]==c[i][j])and(c[i][j+1]==c[i][j])) rd[i][j]=min(rd[i+1][j],rd[i][j+1])+1;
    	else rd[i][j]=1;
    }
    for (i=1;i<=n;i++) for (j=1;j<=m;j++)
    {
    	t+=min(min(lu[i][j],ru[i][j]),min(ld[i][j],rd[i][j]));
    }
    cout<<t;
}