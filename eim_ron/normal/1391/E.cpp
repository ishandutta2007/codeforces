
// Problem : E. Pairs of Pairs
// Contest : Codeforces - Codeforces Round #663 (Div. 2)
// URL : https://codeforces.com/contest/1391/problem/E
// Memory Limit : 256 MB
// Time Limit : 3000 ms
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
int n,m,k,c[501],used[500001],t,t1,i,j,tt,tt1;
vector<int> gt[500001],lay[500001]; int par[500001];
vector<pii> pr;
void dfs (int cur, int p, int l)
{
	par[cur]=p;
	lay[l].push_back(cur);
	used[cur]=1;
	for (int g : gt[cur]) if (!used[g]) dfs(g,cur,l+1);
}
void path (int x)
{
	cout<<x<<' ';
	if (x!=1) path(par[x]);
}
int main()
{
//  ofile;
    fio;
    cin>>tt;
    for (tt1=0;tt1<tt;tt1++)
    {
    cin>>n>>m;
    for (i=1;i<=n;i++)
    {
    	used[i]=0;
    	par[i]=0;
    	gt[i].clear();
    	lay[i].clear();
    }
    pr.clear();
    for (i=1;i<=m;i++)
    {
    	cin>>t>>t1;
    	gt[t].push_back(t1);
    	gt[t1].push_back(t);
    }
    dfs(1,0,1);
    if (lay[int(ceil(double(n)/2))].size()) {cout<<"PATH"<<endl<<int(ceil(double(n)/2))<<endl; path(lay[int(ceil(double(n)/2))][0]);cout<<endl;}
	else
	{
		for (i=0;i<n;i++) for (j=0;j+1<lay[i].size();j+=2) pr.push_back({lay[i][j],lay[i][j+1]});
		cout<<"PAIRING"<<endl<<pr.size()<<endl;
		for (pii g : pr) cout<<g.fi<<' '<<g.se<<endl;
	}
	}
}