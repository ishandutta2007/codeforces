#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <functional>
#include <queue>
 
using namespace std;
#define fi first
#define sc second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<ll,int> P;
int n,q;
ll d[100005];
ll t[100005];
ll seg1[(1<<19)];
int id1[(1<<19)];
ll seg2[(1<<19)];
int id2[(1<<19)];
void update1(int a,ll x)
{
	a += (1<<18)-1;
	seg1[a] = max(seg1[a],x);
	while(a > 0)
	{
		a = (a-1)/2;
		if(seg1[a*2+1] < seg1[a*2+2])
		{
			seg1[a] = seg1[a*2+2];
			id1[a] = id1[a*2+2];
		}
		else
		{
			seg1[a] = seg1[a*2+1];
			id1[a] = id1[a*2+1];
		}
	}
}
P query1(int a,int b,int k,int l,int r)
{
	if(r<a || b<l || a>b) return mp(-1ll,-1);
	if(a<=l && r<=b) return mp(seg1[k],id1[k]);
	P lb = query1(a,b,k*2+1,l,(l+r)/2);
	P rb = query1(a,b,k*2+2,(l+r)/2+1,r);
	if(lb.fi < rb.fi) return rb;
	else return lb;
}
void update2(int a,ll x)
{
	a += (1<<18)-1;
	seg2[a] = max(seg2[a],x);
	while(a > 0)
	{
		a = (a-1)/2;
		if(seg2[a*2+1] < seg2[a*2+2])
		{
			seg2[a] = seg2[a*2+2];
			id2[a] = id2[a*2+2];
		}
		else
		{
			seg2[a] = seg2[a*2+1];
			id2[a] = id2[a*2+1];
		}
	}
}
P query2(int a,int b,int k,int l,int r)
{
	if(r<a || b<l || a>b) return mp(-1ll,-1);
	if(a<=l && r<=b) return mp(seg2[k],id2[k]);
	P lb = query2(a,b,k*2+1,l,(l+r)/2);
	P rb = query2(a,b,k*2+2,(l+r)/2+1,r);
	if(lb.fi < rb.fi) return rb;
	else return lb;
}
ll rui[200005];
int main()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++) scanf("%lld",&d[i]);
	for(int i=1;i<=n;i++) {scanf("%lld",&t[i]);t[i]*=2;}
	for(int i=1;i<=(1<<18);i++)
	{
		id1[i+(1<<18)-1] = id2[i+(1<<18)-1] = i;
	}
	for(int i=1;i<=2*n;i++)
	{
		if(2<=i && i<=n+1)
		{
			rui[i] = rui[i-1]+d[i-1];
		}
		else
		{
			rui[i] = rui[i-1]+d[i-n-1];
		}
		if(1<=i && i<=n) update1(i,rui[i]+t[i]);
		else update1(i,rui[i]+t[i-n]);
	}
	for(int i=2*n;i>=1;i--)
	{
		if(1<=i && i<=n) update2(i,rui[2*n]-rui[i]+t[i]);
		else update2(i,rui[2*n]-rui[i]+t[i-n]);
	}
	for(int i=0;i<q;i++)
	{
		int a,b; scanf("%d%d",&a,&b);
		int lb,ub;
		if(a<=b) lb = b+1,ub = n+a-1;
		else lb = n+b+1,ub = n+a-1;
		P p = query2(lb,ub,0,0,(1<<18)-1);
		P q = query1(lb,ub,0,0,(1<<18)-1);
		if(p.sc != q.sc)
		{
			cout << p.fi+q.fi-rui[2*n] << endl;
		}
		else
		{
			P p1 = query2(lb,p.sc-1,0,0,(1<<18)-1);
			P q1 = query1(p.sc+1,ub,0,0,(1<<18)-1);
			ll cand1 = p1.fi+q.fi-rui[2*n];
			ll cand2 = p.fi+q1.fi-rui[2*n];
			cout << max(cand1,cand2) << endl;
		}
	}
}