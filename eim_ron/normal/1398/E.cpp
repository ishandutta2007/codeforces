
// Problem : E. Two Types of Spells
// Contest : Codeforces - Educational Codeforces Round 93 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1398/problem/E
// Memory Limit : 256 MB
// Time Limit : 3500 ms
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
#define pii pair<ll,ll>
#define piii pair<ll,pii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
typedef long long ll;
//---------END-------//
struct segment_tree{
    ll seg[4 * 200001];
    
    void build(ll id, ll l, ll r){
        if (l == r){
            seg[id] = 0;
            return;
        }
        ll mid = (l + r) >> 1;
        build(id << 1, l, mid);
        build(id << 1 | 1, mid + 1, r);
        seg[id] = seg[id << 1] + seg[id << 1 | 1];
    }
    
    void update(ll id, ll l, ll r, ll i, ll val){
        if (i < l || r < i){
            return;
        }
        if (l == r){
            seg[id] += val;
            return;
        }
        ll mid = (l + r) >> 1;
        update(id << 1, l, mid, i, val);
        update(id << 1 | 1, mid + 1, r, i, val);
        seg[id] = seg[id << 1] + seg[id << 1 | 1];
    }
    
    ll get(ll id, ll l, ll r, ll u, ll v){
        if (v < l || r < u){
            return 0;
        }
        if (u <= l && r <= v){
            return seg[id];
        }
        ll mid = (l + r) >> 1;
        return get(id << 1, l, mid, u, v) + get(id << 1 | 1, mid + 1, r, u, v);
    }
} sumpow,cnt1;
ll n,m,k,c[501],pos[200001],t,t1,i,j;
vector<piii> events,ord;
pii spells[200001];
ordered_set oss;
int main()
{
//  ofile;
    fio;
    cin>>n;
    for (i=1;i<=n;i++)
    {
    	int typ,pow;
    	cin>>typ>>pow;
    	events.push_back({i,{typ,pow}});
    	ord.push_back({i,{typ,abs(pow)}});
    }
    
    sort(ord.begin(),ord.end(),[](piii a, piii b)
    {if (a.p3-b.p3) return (a.p3<b.p3); if (a.p2-b.p2) return (a.p2<b.p2); return (a.p1<b.p1);});
    j=0; k=0;
    for (i=0;i<n;i++)
    {
    	if ((i==0)or(ord[i].p3!=ord[j].p3)or(ord[i].p2!=ord[j].p2)) { k++; j=i; spells[k]=ord[i].se;}
   // 	cout<<ord[i].p1-1<<endl;
    	events[ord[i].p1-1].p1=k;
    }
    
    ll c0=0,c1=0,cursum=0;
    for (i=0;i<n;i++)
    {
    	if (events[i].p3>0)
    	{
    		oss.insert(events[i].p1);
    		sumpow.update(1,1,k,events[i].p1,abs(events[i].p3));
    		cnt1.update(1,1,k,events[i].p1,abs(events[i].p2));
    		cursum+=abs(events[i].p3);
    		if (events[i].p2) c1++; else c0++;
    	}
    	else
    	{
    		
    		oss.erase(events[i].p1);
    		sumpow.update(1,1,k,events[i].p1,-abs(events[i].p3));
    		cnt1.update(1,1,k,events[i].p1,-abs(events[i].p2));
    		cursum-=abs(events[i].p3);
    		if (events[i].p2) c1--; else c0--;
    	}
    	m=0;
    	if (c1)
    	{
    		m=0;
    		ll lb=(*(oss.find_by_order(c0)));
    		m+=sumpow.get(1,1,k,lb,k);
    		if (cnt1.get(1,1,k,lb,k)==c1) 
    		{
    		m-=spells[lb].se;
    		if (c0) 
    		{
    			lb=(*(oss.find_by_order(c0-1)));
    			
    		m+=spells[lb].se;
    		}
    		}
    	}
    	cout<<cursum+m<<endl;
    }
    /*
    */
}