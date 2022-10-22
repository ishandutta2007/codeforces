#include<bits/stdc++.h>
using namespace std;
const int N=50005;
int n,m,k,rt,z=1,t,lg;
int tr[N<<6],lc[N<<6],rc[N<<6],s[N<<6],vl[N<<6],ans[100];
struct nd
{
	int x,l,r,v;
	bool operator<(const nd k)const
	{
		return x<k.x;
	}
};
vector<nd>p;
int cal(int l,int r)
{
	int v=0;
	for(int i=1;i<=k;i<<=1)
		v|=(((r/i-(l-1)/i)-(i*2<=k?r/i/2-(l-1)/i/2:0))&1)*i;
	return v;
}
void pu(int k)
{
	if(tr[k]) s[k]=vl[k];
	else s[k]=s[lc[k]]^s[rc[k]];
}
void add(int &k,int l,int r,int a,int b,int v)
{
	if(!k)
	{
		k=++t;
		vl[k]=cal(l,r);
	}
	if(l==a&&r==b)
	{
		tr[k]+=v;
		pu(k);
		return;
	}
	int mid=l+r>>1;
	if(b<=mid) add(lc[k],l,mid,a,b,v);
	else if(a>mid) add(rc[k],mid+1,r,a,b,v);
	else add(lc[k],l,mid,a,mid,v),add(rc[k],mid+1,r,mid+1,b,v);
	pu(k);
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	while(z<k)
		z<<=1,lg++;
	for(int i=1;i<=m;i++)
	{
		int xl,xr,yl,yr;
		scanf("%d%d%d%d",&xl,&yl,&xr,&yr);
		p.push_back({xl,yl,yr,1});
		p.push_back({xr+1,yl,yr,-1});
	}
	if(n==1)
	{
		puts(m?"Hamed":"Malek");
		return 0;
	}
	sort(p.begin(),p.end());
	for(int i=0;i<p.size();i++)
	{
		if(i&&p[i].x!=p[i-1].x)
		{
			int vx=s[rt],vy=cal(p[i-1].x,p[i].x-1),sx=0,sy=0;
			for(int j=z,g=lg;j;j>>=1,g--)
			{
				if(vx&j) sx++;
				if(vy&j) sy++;
				ans[g]+=sx*sy;	
			}
		}
		add(rt,1,n,p[i].l,p[i].r,p[i].v);
	}
	for(int i=0;i<lg;i++)
	{
		if((ans[i]-ans[i+1])&1)
		{
			puts("Hamed");
			return 0;
		}
	}
	puts("Malek");
	return 0;
}