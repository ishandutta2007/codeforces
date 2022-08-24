#include<bits/stdc++.h>
#define L long long
using namespace std;
const int q=1000000007,t=30;
const L inf=1000000010;
int n,m,x[200010],p,u,v,ww,pp[100010];
struct orz
{
	int a,b,c,d,e;
}w;
vector<orz> f[400010];
inline void xds(int i,int l,int r)
{
	if(l<r)
	  {
	   xds(i<<1,l,l+r>>1);
	   xds(i<<1|1,(l+r>>1)+1,r);
	  }
	int j,k,u,v,b,c;
	for(j=0;;)
	  {
	   w.b=1;
	   w.c=0;
	   w.a=w.d=w.e=j;
	   for(k=r,b=c=0,u=0;k>=l;k--)
	     {
		  if(w.d<=0)
		    {
			 if(!u)
			   {
				u=k;
				v=-w.d;
			   }
			 b=(b+w.b*2ll)%q;
			 c=(c+w.c*2ll)%q;
			 w.b=w.c=w.d=w.e=0;
			}
			 w.b=(w.b<<1)%q;
			 w.c=(w.c*2ll+x[k])%q;
			 w.d=min(w.d*2ll+x[k],inf);
			 w.e=(w.e*2ll+x[k])%q;
		 }
	   w.b=b;
	   w.c=c;
	   f[i].push_back(w);
	   if(!u)
	     break;
	   if(r-u>t)
	     j++;
	   else
	    {
			//cout<<v<<" "<<u<<"--\n";
	     j+=v/(1<<r-u)+1;
		}
	  }
	/*  cout<<i<<" "<<l<<" "<<r<<"!!!\n";
	for(j=0;j<f[i].size();j++)
	  cout<<f[i][j].b<<" ";
	  cout<<"\n";*/
}
inline int xxx(int i)
{
	if(i>t)
	  return inf;
	else
	  return 1<<i;
}
inline void query(int i,int l,int r,int j,int k)
{
	if(j<=l && r<=k)
	  {
	   int p;
	   if(ww<0)
	     {
		  v=(v+ww*2ll)%q;
		  u=ww=0;
		 }
	   for(p=0;p+1<f[i].size() && ww>=f[i][p+1].a;p++);
	   v=(v+(L)f[i][p].b*u+f[i][p].c)%q;
	   if(p+1==f[i].size())
	     {
		  u=(f[i][p].e+(L)(u-f[i][p].a)*pp[r-l+1])%q;
	      ww=min(inf,f[i][p].d+(L)(ww-f[i][p].a)*xxx(r-l+1));
		 }
	   else
	     {
		  u=f[i][p].e;
	      ww=f[i][p].d;
		 }
		 //cout<<i<<" "<<l<<" "<<r<<" "<<p<<" "<<f[i][p].b<<" "<<f[i][p].c<<" "<<u<<" "<<ww<<" "<<v<<"!!!"<<"\n";
		 //cout<<f[i][p].a<<" "<<f[i][p].b<<" "<<f[i][p].c<<" "<<f[i][p].d<<" "<<f[i][p].e<<"\n";
	  }
	else
	  {
	   if(k>(l+r>>1))
	     query(i<<1|1,(l+r>>1)+1,r,j,k);
	   if(j<=(l+r>>1))
	     query(i<<1,l,l+r>>1,j,k);
	  }
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	  scanf("%d",&x[i]);
	for(p=1;p<n;p<<=1);
	xds(1,1,p);
	pp[0]=1;
	for(i=1;i<=n;i++)
	  pp[i]=(pp[i-1]<<1)%q;
	while(m--)
	  {
	   scanf("%d%d",&i,&j);
	   u=v=ww=0;
	   query(1,1,p,i,j);
	   printf("%d\n",((u+v)%q+q)%q);
	  }
	return 0;
}