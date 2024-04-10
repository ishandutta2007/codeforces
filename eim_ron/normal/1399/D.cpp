
// Problem : D. Binary String To Subsequences
// Contest : Codeforces - Codeforces Round #661 (Div. 3)
// URL : https://codeforces.com/contest/1399/problem/D
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
int n,m,k,c[501],pos[200001],t,t1,i,j;
vector<ll> s0,s1;
int main()
{
//  ofile;
    fio;
    cin>>t;
    for (t1=0;t1<t;t1++)
    {
    	cin>>n;
    	string s;
    	cin>>s; s0.clear(); s1.clear();
    	for (i=1;i<=n;i++)
    	
    	{
    		if (s[i-1]=='0')
    		{
    			if (s1.size())
    			{
    				pos[i]=s1[s1.size()-1];
    				s1.pop_back();
    				s0.push_back(pos[i]);
    			}
    			else
    			{
    				pos[i]=s0.size()+s1.size()+1;
    				s0.push_back(pos[i]);
    			}
    		}
    		else
    		
    		if (s[i-1]=='1')
    		{
    			if (s0.size())
    			{
    				pos[i]=s0[s0.size()-1];
    				s0.pop_back();
    				s1.push_back(pos[i]);
    			}
    			else
    			{
    				pos[i]=s1.size()+s0.size()+1;
    				s1.push_back(pos[i]);
    			}
    		}
    	}
    	cout<<s0.size()+s1.size();
    	cout<<endl;
    	for (i=1;i<=n;i++) cout<<pos[i]<<' ';
    	cout<<endl;
    }
}