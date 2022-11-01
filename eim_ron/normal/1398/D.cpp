
// Problem : Colored Rectangles
// Contest : Codeforces
// URL : https://m1.codeforces.com/contest/1398/problem/D
// Memory Limit : 256 MB
// Time Limit : 2000 ms
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
int nr,ng,nb,m,k,c[501],pos[100001],t,t1,i,j;
int dp[201][201][201];
vector<int> lr,lg,lb;
int main()
{
//  ofile;
    fio;
    cin>>nr>>ng>>nb;
    for (i=0;i<nr;i++) {cin>>m; lr.push_back(m);} sort(lr.begin(),lr.end());
    for (i=0;i<ng;i++) {cin>>m; lg.push_back(m);} sort(lg.begin(),lg.end());
    for (i=0;i<nb;i++) {cin>>m; lb.push_back(m);} sort(lb.begin(),lb.end());
    for (int ir=0;ir<=nr;ir++) for (int ig=0;ig<=ng;ig++) for (int ib=0;ib<=nb;ib++)
    {
    	dp[ir][ig][ib]=0;
    	if (ir*ig) dp[ir][ig][ib]=max(dp[ir][ig][ib],dp[ir-1][ig-1][ib]+lr[ir-1]*lg[ig-1]);
    	if (ig*ib) dp[ir][ig][ib]=max(dp[ir][ig][ib],dp[ir][ig-1][ib-1]+lg[ig-1]*lb[ib-1]);
    	if (ib*ir) dp[ir][ig][ib]=max(dp[ir][ig][ib],dp[ir-1][ig][ib-1]+lb[ib-1]*lr[ir-1]);
    }
    cout<<dp[nr][ng][nb];
}