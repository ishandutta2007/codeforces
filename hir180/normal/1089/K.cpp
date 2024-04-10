#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <cmath>
#include <string>
#define SIZE 300005
#define BT 1024*1024*2
#define INF 100000000000000000LL

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

struct segtree
{
	ll seg[BT],add[BT];
	int mum;
	
	void init()
	{
		mum=BT/2;
		for(int i=0;i<mum*2;i++) seg[i]=-INF,add[i]=0;
	}
	void update(int a,int b,int k,int l,int r,ll v)
	{
		if(b<=l||r<=a) return;
		if(a<=l&&r<=b) seg[k]+=v,add[k]+=v;
		else
		{
			update(a,b,k*2+1,l,(l+r)/2,v);
			update(a,b,k*2+2,(l+r)/2,r,v);
			seg[k]=max(seg[k*2+1],seg[k*2+2])+add[k];
		}
	}
	void update(int a,int b,ll v)
	{
		update(a,b,0,0,mum,v);
	}
	ll get(int a,int b,int k,int l,int r)
	{
		if(b<=l||r<=a) return -INF;
		if(a<=l&&r<=b) return seg[k];
		else
		{
			ll vl=get(a,b,k*2+1,l,(l+r)/2);
			ll vr=get(a,b,k*2+2,(l+r)/2,r);
			return max(vl,vr)+add[k];
		}
	}
	ll get(int a,int b)
	{
		return get(a,b,0,0,mum);
	}
	ll gsum(int k)
	{
		k+=mum-1;
		ll ret=add[k];
		while(k>0)
		{
			k=(k-1)/2;
			ret+=add[k];
		}
		return ret;
	}
}seg;
int T[SIZE],D[SIZE];
char str[SIZE];
bool use[BT];

int main()
{
	int Q;
	scanf("%d",&Q);
	seg.init();
	int sz=0;
	while(Q--)
	{
		scanf("%s",&str);
		if(str[0]=='?')
		{
			int t;
			scanf("%d",&t);
			ll g=seg.get(0,t+1);
			g-=seg.gsum(t+1);
			g-=t;
			if(use[t+1]) g+=INF+(t+1);
			//printf("* %lld\n",g);
			printf("%lld\n",max(0LL,g));
		}
		else if(str[0]=='+')
		{
			scanf("%d %d",&T[sz],&D[sz]);
			seg.update(T[sz],T[sz]+1,INF+T[sz]);
			seg.update(0,T[sz]+1,D[sz]);
			use[T[sz]]=true;
		}
		else
		{
			int i;
			scanf("%d",&i);i--;
			seg.update(0,T[i]+1,-D[i]);
			seg.update(T[i],T[i]+1,-INF-T[i]);
			use[T[i]]=false;
		}
		sz++;
	}
	return 0;
}