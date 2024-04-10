
// Problem : Good Subarrays
// Contest : Codeforces
// URL : https://m1.codeforces.com/contest/1398/problem/C
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
ll n,m,k,c[501],arr[100001],psum[100001],t,t1,i,j;
vector<ll> lis;
int main()
{
//  ofile;
    fio;
    cin>>t;
    for  (t1=0;t1<t;t1++)
    {
    	cin>>n;
    	lis.clear();
    	m=0;
    	for (i=1;i<=n;i++)
    	{
    		char cc;
    		cin>>cc;
    		arr[i]=cc-48;
    		psum[i]=psum[i-1]+arr[i];
    	}
    	for (i=0;i<=n;i++) lis.push_back(psum[i]-i);
    	sort(lis.begin(),lis.end());
    	j=0;
    	for (i=1;i<=n;i++)
    	{
    		if (lis[i]!=lis[j]) {m+=(i-j)*(i-j-1)/2; j=i;}
    	}
    	{m+=(i-j)*(i-j-1)/2; j=i;}
    	cout<<m<<endl;
    }
}