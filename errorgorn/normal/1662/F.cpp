#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

const long long inf=1e18;
long long n,st,fn,a[200069],nr[200069];
pair<long long,long long> as[200069];
queue<long long> q;

struct segtree
{
	long long l,r,cr[2];
	vector<pair<long long,long long>> vl[2];
	segtree *p[2];
	
	void bd(long long lh,long long rh)
	{
		long long ii,md=(lh+rh)/2;
		
		l=lh;
		r=rh;
		for(ii=0;ii<2;ii++)
		{
			vl[ii].clear();
			cr[ii]=-1;
		}
		if(l<r)
		{
			for(ii=0;ii<2;ii++)
			{
				p[ii]=new segtree;
				p[ii]->bd(!ii?l:md+1,!ii?md:r);
			}
		}
	}
	void ins(long long xx,long long x,long long w)
	{
		if(l>x||r<x);
		else
		{
			vl[xx].push_back({w,x});
			cr[xx]++;
			if(l<r)
			{
				long long ii;
				
				for(ii=0;ii<2;ii++)
				{
					p[ii]->ins(xx,x,w);
				}
			}
		}
	}
	void qr(long long xx,long long lh,long long rh,long long db,long long w)
	{
		if(l>rh||r<lh);
		else if(l>=lh&&r<=rh)
		{
			long long k;
			
			for(;cr[xx]>=0&&vl[xx][cr[xx]].fr>=db;cr[xx]--)
			{
				k=vl[xx][cr[xx]].sc;
				if(w<nr[k])
				{
					q.push(k);
					nr[k]=w;
				}
			}
		}
		else
		{
			long long ii;
			
			for(ii=0;ii<2;ii++)
			{
				p[ii]->qr(xx,lh,rh,db,w);
			}
		}
	}
}
sg;

int main()
{
	long long t,rr,i,ii,u,k,l,k2,l2;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld",&n,&st,&fn);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
			nr[i]=inf;
		}
		sg.bd(1,n);
		for(ii=0;ii<2;ii++)
		{
			u=!ii*2-1;
			for(i=1;i<=n;i++)
			{
				as[i]={a[i]+i*u,i};
			}
			sort(as+1,as+n+1);
			for(i=1;i<=n;i++)
			{
				k=as[i].fr;
				l=as[i].sc;
				sg.ins(ii,l,k);
			}
		}
		q.push(st);
		nr[st]=0;
		for(;!q.empty();)
		{
			k=q.front();
			q.pop();
			for(ii=0;ii<2;ii++)
			{
				u=!ii*2-1;
				k2=k;
				l2=k-a[k]*u;
				if(k2>l2)
				{
					swap(k2,l2);
				}
				sg.qr(ii,k2,l2,k*u,nr[k]+1);
			}
		}
		printf("%lld\n",nr[fn]);
	}
}