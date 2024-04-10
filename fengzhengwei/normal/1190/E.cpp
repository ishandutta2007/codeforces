#include<bits/stdc++.h>
#define ll long long
#define dd long double
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
//#define getchar gc
ll read()
{
	char c;
	ll w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	ll ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
void pc(char c,int op)
{
	static char buf[1<<16],*s=buf,*t=buf+(1<<16);
	(op||((*s++=c)&&s==t))&&(fwrite(buf,1,s-buf,stdout),s=buf);
}
void wt(int x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(int x,char op)
{
	if(x<0)pc('-',0),x=-x;
	wt(x),pc(op,0);
}
const int xx=1e5+5;
int n,m;
struct pt{dd x,y;}e[xx];
//,q[xx];
dd cross(const pt&a,const pt&b,const pt&c){return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);}
const dd eps=1e-7;
dd dis(const pt&a,const pt&b){return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));}
//a(b,c) 
dd Dis(const pt&a,const pt&b,const pt&c){return abs(cross(a,b,c))/dis(b,c);}
//log^2sort 
dd d[xx],alf[xx];// 
const dd pi=3.14159265358979323846;
int id[xx<<1],vis[xx<<1],to[xx<<1];
//dd tl[xx],tr[xx];
struct nod
{
	dd l,r;
	bool operator<(const nod&w)const{return r<w.r;/*l==w.l?r>w.r:l<w.l;*/}
}q[xx<<1];
int f[xx<<1][21];
bool check(dd R)
{
	for(int i=1;i<=n;i++)
	{
		dd b=dis(e[i],e[0]),c=R,a=sqrt(b*b-c*c);
		q[i].l=q[i].r=atan2(e[i].y,e[i].x);
		(alf[i]=acos((b*b+c*c-a*a)/(2*b*c)));
		q[i].l-=alf[i],q[i].r+=alf[i];
//		d[i]=atan2(e[i].y,e[i].x);
//		if(d[i]>pi)d[i]-=pi,d[i]-=pi;
		if(q[i].r>pi)q[i].l-=pi+pi,q[i].r-=pi+pi;
		id[i]=i;
	}
	sort(q+1,q+n+1);
	//a 
//	for(int i=1;i<=n;i++)cout<<q[i].l<<" "<<q[i].r<<"!!\n";
	for(int i=1;i<=n;i++)q[i+n]=q[i];
	for(int i=1;i<=n;i++)q[i+n].l+=pi+pi,q[i+n].r+=pi+pi;
	int to=1;
	for(int i=1;i<=n+n;i++)
	{
		while(to<n+n&&q[to+1].l<=q[i].r)to++;
		f[i][0]=to+1;
//		cout<<to+1<<"!!\n";
	}
	f[n+n+1][0]=n+n+1;
	for(int j=1;j<=20;j++)for(int x=1;x<=n+n+1;x++)f[x][j]=f[f[x][j-1]][j-1];
//	,cerr<<x<<" "<<j<<" "<<f[x][j]<<"WEf\n";
	for(int i=1;i<=n;i++)
	{
		int num=0;
		int x=i;
		for(int j=20;j>=0;j--)
		{
//			cerr<<j<<" "<<x<<" "<<f[x][j]<<"!\n";
			if(f[x][j]<i+n)x=f[x][j],num+=(1<<j);
		}
//		cerr<<num<<" "<<i<<"!!\n";
		num++;
		if(num<=m)return 1;
	}
//	int tt=0;
//	dd mx=-1e18;
//	for(int i=1;i<=n;i++)
//	{
//		if(mx>=e[i].r)continue;
//		mx=e[i].r,q[++tt]=q[i];
//	}
	
//	sort(id+1,id+n+1,[&](int a,int b){return d[a]<d[b];});
//	//reverse 
//	reverse(id+1,id+n+1);
//	for(int i=1;i<=n;i++)id[i+n]=id[i];
//	int ls=1;
	//cross<=0 
	// 
//	for(int i=1;i<=n;i++)
//		q[i]={e[i].x*cos(alf[i])-e[i].y*sin(alf[i]),e[i].y*cos(alf[i])+e[i].x*sin(alf[i])};
//	for(int i=1;i<=n;i++)
//	{
//		dd bs=R/dis(e[i],e[0]);
//		q[i].x*=bs,q[i].y*=bs;
//	}
	// 
//	for(int i=1;i<=n;i++)cout<<q[i].x<<" "<<q[i].y<<"!s!\n";
//	for(int i=1;i<=n+n;i++)
//	{
//		while(ls<i&&cross(e[id[i]],q[id[i]],e[id[ls]])>0)ls++;
//		to[ls]=i;
//	}
//	for(int i=1;i<=n+n;i++)to[i]=max(to[i],to[i-1]);
//	for(int i=1;i<=n+n;i++)vis[i]=0;
//	for(int i=1;i<=n+n;i++)cout<<i<<" "<<id[i]<<"!!\n";
//	for(int i=1;i<=n+n;i++)
//	{
//		if(vis[i])continue;
//		int st=i,ed=i,len=0;
//		while(st<=n)
//		{
//			vis[st]=1;
//			while(ed<st+n)ed=to[ed]+1,vis[ed]=1,len++;
////			cerr<<st<<' '<<
//			if(len<=m)return 1;
//			len--,st=to[st]+1;
//		}
//	}
//	puts("Dfgfdg");
	return 0;
}
int main(){
	n=read(),m=read();
	e[0].x=e[0].y=0;
	for(int i=1;i<=n;i++)
		scanf("%Lf%Lf",&e[i].x,&e[i].y);
	dd l=0,r=1e18,ans=0;
	for(int i=1;i<=n;i++)r=min(r,dis(e[i],e[0]));
//	cout<<l<<' '<<r<<"!!\n";
//	cout<<check(1)<<"!!\n";
//	exit(0);
	while(l+eps<=r)
	{
		dd mid=(l+r)/2.0;
		if(check(mid))ans=mid,l=mid;
		else r=mid;
	}
	if(ans<0.001)ans=0;
	cout<<fixed<<setprecision(6)<<ans<<"\n";
	pc('1',1);
	return 0;
}