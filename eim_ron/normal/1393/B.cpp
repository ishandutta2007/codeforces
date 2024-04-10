
// Problem : B. Applejack and Storages
// Contest : Codeforces - Codeforces Round #662 (Div. 2)
// URL : https://codeforces.com/contest/1393/problem/B
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
int arr[100001]; int cnt4,cnt2;
int main()
{
//  ofile;
    fio;
    cin>>n;
    for (i=1;i<=n;i++)
    {
 		cin>>k;
 		arr[k]++;   	
    }
    for (i=1;i<=100000;i++)
    {
    	
    	cnt4+=arr[i]/4;
    	cnt2+=arr[i]/2;
    }
    cin>>m;
    for (i=1;i<=m;i++)
    {
    	char c;
    	cin>>c>>k;
    	cnt4-=arr[k]/4;
    	cnt2-=arr[k]/2;
    	if (c=='+') arr[k]++;
    	else arr[k]--;
    	cnt4+=arr[k]/4;
    	cnt2+=arr[k]/2;
 //   	cout<<cnt4<<' '<<cnt2<<endl;
    	if ((cnt4-1>=0)and(cnt2-4>=0)) cout<<"YES"; else cout<<"NO";
    	cout<<endl;
    }
}