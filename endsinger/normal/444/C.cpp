#include<bits/stdc++.h>
using namespace std;
const int N=100005;
long long sumv[N<<2],addv[N<<2],setv[N<<2];
int typ,ql,qr,qv;
void Pushup(int o,int l,int r)
{
	setv[o]=setv[o*2]==setv[o*2+1] ? setv[o*2] : 0;
	sumv[o]=sumv[o*2]+sumv[o*2+1];
}
void Pushdown(int o,int l,int r)
{
	int mid=l+r>>1;
	if(setv[o])
	{
		setv[o*2]=setv[o*2+1]=setv[o];
		addv[o*2]+=addv[o]; addv[o*2+1]+=addv[o];
		sumv[o*2]+=addv[o]*(mid-l);
		sumv[o*2+1]+=addv[o]*(r-mid);
		setv[o]=addv[o]=0;
	}
}
void Update(int o,int l,int r)
{
	if(ql<=l&&r<=qr&&setv[o])
	{
		addv[o]+=abs(qv-setv[o]);
		sumv[o]+=(long long)abs(qv-setv[o])*(r-l);
		setv[o]=qv;
	}
	else
	{
		int mid=l+r>>1;
		Pushdown(o,l,r);
		if(ql<mid) Update(o*2,l,mid);
		if(qr>mid) Update(o*2+1,mid,r);
		Pushup(o,l,r);
	}
}
long long Query(int o,int l,int r)
{
	if(ql<=l&&r<=qr) 
		return sumv[o];
	else
	{
		int mid=l+r>>1;
		long long rnt=0;
		Pushdown(o,l,r);
		if(ql<mid) rnt+=Query(o*2,l,mid);
		if(qr>mid) rnt+=Query(o*2+1,mid,r);
		return rnt;
	}
}
void Build(int o,int l,int r)
{
	if(l+1==r) 
		setv[o]=l;
	else
	{
		int mid=l+r>>1;
		Build(o*2,l,mid);
		Build(o*2+1,mid,r);
	}
}
int main()
{
	int n,m; 
	scanf("%d%d",&n,&m);
	Build(1,1,n+1);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&typ,&ql,&qr); 
		qr++;
		if(typ==1){
			scanf("%d",&qv);
			Update(1,1,n+1);
		}
		else 
			printf("%lld\n",Query(1,1,n+1));
	}
	return 0;
}