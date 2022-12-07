#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<complex>
#include<iostream>
#include<algorithm>
#define K 11
#define N 100001
#define int long long
#define LOG(x) cerr<<#x<<" = "<<x<<endl
#define add_edge(u,v) nxt[++cnt]=head[u],head[u]=cnt,to[cnt]=v
#define open(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
char ch;bool fs;void re(int& x)
{
	while(ch=getchar(),ch<33);
	if(ch=='-')fs=1,x=0;else fs=0,x=ch-48;
	while(ch=getchar(),ch>33)x=x*10+ch-48;
	if(fs)x=-x;
}
using namespace std;
struct node
{
	int x,y;
	bool operator < (const node &i)const
	{
		return atan2(y,x)<atan2(i.y,i.x);
	}
}v[K];
struct work
{
	double a;
	int x,y,z;
	bool operator < (const work &i)const
	{
		return fabs(a-i.a)<1e-7?z<i.z:a<i.a;
	}
}w[N+N];
int ans[N],px[N],py[N],t[N];
int k,n,q,sx,sy,hn,fx[N],fy[N],a[N],ha[N];
int s[N];
int ps(int x){return upper_bound(ha+1,ha+hn+1,x)-ha-1;}
void add(int x,int y)
{
	// cerr<<x<<" "<<y<<endl;
	for(;x<N;x+=x&-x)
		s[x]+=y;
}
int ask(int x)
{
	int res=0;
	for(;x;x-=x&-x)
		res+=s[x];
	return res;
}
main()
{
	re(k),re(n),re(q);
	for(int i=1;i<=k;++i)
	{
		re(v[i].x),re(v[i].y);
		if(v[i].x<0)v[i].x*=-1,v[i].y*=-1;
		if(v[i].x==0 && v[i].y<0)v[i].y*=-1;
		sx+=v[i].x;sy+=v[i].y;
	}
	sort(v+1,v+k+1);
	for(int i=1;i<=n;++i)
		re(fx[i]),re(fy[i]),re(a[i]),ha[i]=fx[i];
	sort(ha+1,ha+n+1);
	hn=unique(ha+1,ha+n+1)-ha-1;
	for(int i=1;i<=q;++i)
	{
		re(px[i]);re(py[i]);re(t[i]);
		px[i]-=sx*t[i];py[i]-=sy*t[i];t[i]*=2;
	}
	for(int i=1;i<=k;++i)
	{
		if(!v[i].x){for(int j=1;j<=q;++j)py[j]+=v[i].y*t[j];continue;}
		for(int j=1;j<=n;++j)w[j]=(work){fy[j]-(double)fx[j]/v[i].x*v[i].y,fx[j],a[j],0};
		for(int j=1;j<=q;++j)w[n+j]=(work){py[j]-(double)px[j]/v[i].x*v[i].y,px[j],px[j]+v[i].x*t[j],-j},
			px[j]+=v[i].x*t[j],py[j]+=v[i].y*t[j];
		sort(w+1,w+n+q+1);

		memset(s,0,sizeof s);
		for(int j=1;j<=n+q;++j)
			if(w[j].z)ans[-w[j].z]-=ask(ps(w[j].y))-ask(ps(w[j].x-(i<2)));
			else add(ps(w[j].x),w[j].y);
	}
	for(int i=1;i<=k;++i)
	{
		if(!v[i].x)break;
		for(int j=1;j<=n;++j)w[j]=(work){fy[j]-(double)fx[j]/v[i].x*v[i].y,fx[j],a[j],0};
		for(int j=1;j<=q;++j)w[n+j]=(work){py[j]-(double)px[j]/v[i].x*v[i].y,px[j]-v[i].x*t[j],px[j],j},
			px[j]-=v[i].x*t[j],py[j]-=v[i].y*t[j];
		sort(w+1,w+n+q+1);
		// for(int j=1;j<=n+q;++j)
            // cerr<<w[j].a<<" "<<w[j].x<<" "<<w[j].y<<" "<<w[j].z<<endl;
		memset(s,0,sizeof s);
		for(int j=1;j<=n+q;++j)
			if(w[j].z)ans[w[j].z]+=ask(ps(w[j].y-(i>1)))-ask(ps(w[j].x-1));
			else add(ps(w[j].x),w[j].y);
	}
	for(int i=1;i<=q;++i)
		printf("%lld\n",ans[i]);
}