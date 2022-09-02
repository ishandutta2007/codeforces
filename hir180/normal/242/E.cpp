#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;
#define s (1<<17)
struct segtree
{
	int seg[s*2];
	bool lazy[s*2];
	void lazy_evaluate(int k,int l,int r)
	{
		if(lazy[k]) seg[k]=r-l+1-seg[k];
		if(k>=s-1){ lazy[k]=0; return ;}
		lazy[k*2+1]^=lazy[k];
		lazy[k*2+2]^=lazy[k];
		lazy[k]=0;
	}
	int update(int a,int b,int k,int l,int r)
	{
		lazy_evaluate(k,l,r);
		if(b<l || r<a) return seg[k];
		if(a<=l && r<=b)
		{
			lazy[k]^=1;
			lazy_evaluate(k,l,r);
			return seg[k];
		}
		int lko=update(a,b,k*2+1,l,(l+r)/2);
		int rko=update(a,b,k*2+2,(l+r)/2+1,r);
		return seg[k]=lko+rko;
	}
	int query(int a,int b,int k,int l,int r)
	{
		lazy_evaluate(k,l,r);
		if(b<l || r<a) return 0;
		if(a<=l && r<=b)
		{
			return seg[k];
		}
		int lko=query(a,b,k*2+1,l,(l+r)/2);
		int rko=query(a,b,k*2+2,(l+r)/2+1,r);
		return lko+rko;
	}
}seg[20];
int num[100005],n;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&num[i]);	
		for(int j=0;j<20;j++) if(((num[i]>>j)&1)) seg[j].update(i,i,0,0,s-1);
	}
	int q; scanf("%d",&q);
	for(int i=0;i<q;i++)
	{
		int t; cin >> t;
		if(t==1)
		{
			int a,b; cin >> a >> b;
			long long res=0;
			for(int j=0;j<20;j++) res+=(1LL<<j)*seg[j].query(a,b,0,0,s-1);
			cout << res << endl;
		}
		else
		{
			int a,b,v; cin >> a >> b >> v;
			for(int j=0;j<20;j++) if(((v>>j)&1)) seg[j].update(a,b,0,0,s-1);
		}
	}
}