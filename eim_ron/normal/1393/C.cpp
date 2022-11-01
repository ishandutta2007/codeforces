
// Problem : C. Pinkie Pie Eats Patty-cakes
// Contest : Codeforces - Codeforces Round #662 (Div. 2)
// URL : https://codeforces.com/contest/1393/problem/C
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
int n,m,k,c[501],pos[100001],t,t1,i,j;
vector<int> lis,ord;
int cmp (int a, int b)
{
	if (pos[a]-pos[b]) return (pos[a]>pos[b]);
	return (a>b);
}
int check(int x)
{
//	cout<<x<<endl;
	int j=0;
	
	ord.clear();
	int buc=n/x;
	int add=(n%x);
	for (int i=0;i<add;i++) for (int j=0;j<buc+1;j++) ord.push_back(j);
	for (int i=add;i<x;i++) for (int j=0;j<buc;j++) ord.push_back(j);
//	for (int i=0;i<n;i++) cout<<ord[i]<<' '; cout<<endl;
	for (int i=0;i<n;i++)
	{
		if ((i==0)or(lis[i]!=lis[i-1])) j=ord[i];
		else if (ord[i]==j) return 0;
	}
	return 1;
}
int bs (int l, int r)
{
	if (l==r) return l;
	int mid=(l+r)/2+1;
	if (check(mid)) return bs(mid,r); else return bs(l,mid-1);
}
int main()
{
//  ofile;
    fio;
    cin>>t;
    for (t1=0;t1<t;t1++)
    {
    lis.clear();
    	cin>>n;
    for (i=1;i<=n;i++) pos[i]=0;
    for (j=1;j<=n;j++)
    {
    	cin>>k;
    	pos[k]++;
    	lis.push_back(k);
    }
    sort(lis.begin(),lis.end(),cmp);
    cout<<bs(1,n-1)-1<<endl;
    }
}