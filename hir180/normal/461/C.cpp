//very cool problem :-)
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef pair<long long,long long> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
typedef long long ll;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define sz (1<<17)
int seg[(1<<18)];
bool rev = false;
int beg,en,n,q;
void update(int pos,int v)
{
	pos += sz-1;
	seg[pos] += v;
	while(pos > 0)
	{
		pos = (pos-1)/2;
		seg[pos] = seg[pos*2+1]+seg[pos*2+2];
	}
}
int query(int a,int b,int k,int l,int r)
{
	if(r<a || b<l) return 0;
	if(a<=l && r<=b) return seg[k];
	else{
		int vl=query(a,b,k*2+1,l,(l+r)/2);
		int vr=query(a,b,k*2+2,(l+r)/2+1,r);
		return (vl+vr);
	}
}
int main()
{
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		update(i,1);
	}
	beg = 1; en = n;
	for(int i=0;i<q;i++)
	{
		int t; scanf("%d",&t);
		if(t == 1)
		{
			int p; scanf("%d",&p);
			if(!rev)
			{
				if(p*2 <= en-beg+1)
				{
					for(int i=beg;i<beg+p;i++)
					{
						update( (beg+p)*2-1-i,seg[sz-1+i]);
					}
					for(int i=beg;i<beg+p;i++)
					{
						update( i,-seg[sz-1+i]);
					}
					beg += p;
				}
				else
				{
					rev = true;
					for(int i=beg+p;i<=en;i++)
					{
						update( (beg+p)*2-1-i,seg[sz-1+i]);
					}
					for(int i=beg+p;i<=en;i++)
					{
						update( i,-seg[sz-1+i]);
					}
					en = beg+p-1;
				}
			}
			else
			{
				if(p*2 <= en-beg+1)
				{
					for(int i=en-p+1;i<=en;i++)
					{
						update( (en-p)*2+1-i,seg[sz-1+i]);
					}
					for(int i=en-p+1;i<=en;i++)
					{
						update( i,-seg[sz-1+i]);
					}
					en -= p;
				}
				else
				{
					rev = false;
					for(int i=beg;i<=en-p;i++)
					{
						update( (en-p)*2+1-i,seg[sz-1+i]);
					}
					for(int i=beg;i<=en-p;i++)
					{
						update( i,-seg[sz-1+i]);
					}
					beg = en-p+1;
				}
			}
		}
		else
		{
			int l,r;
			scanf("%d %d",&l,&r);
			if(!rev) printf("%d\n",query(beg+l,beg+r-1,0,0,sz-1));
			else printf("%d\n",query(en-r+1,en-l,0,0,sz-1));
		}
	}
}