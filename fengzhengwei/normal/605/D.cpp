#include<bits/stdc++.h>
#define ll long long
#define dd double
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
//#define getchar gc
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
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
	wt(x);pc(op,0);
}
int n;
const int xx=1e5+5;
struct nod{int a,b,c,d;}e[xx];
int lsh1[xx<<1],lsh2[xx<<1],v1[xx<<1],v2[xx<<1],tt1,tt2;
namespace seg
{
	struct nod{int mn,id;}e[xx<<3];// 
	//mx 
	nod upd(nod a,nod b){if(!a.id)return b;if(!b.id)return a;if(a.mn<b.mn)return a;return b;}
	void cg(int k,int l,int r,int x,nod z)
	{
		if(l==r)return e[k]=z,void();
		int mid=l+r>>1;
		if(x<=mid)cg(k<<1,l,mid,x,z);
		else cg(k<<1|1,mid+1,r,x,z);
		e[k]=upd(e[k<<1],e[k<<1|1]);
	}
	nod ask(int k,int l,int r,int x,int y)
	{
		if(x<=l&&r<=y)return e[k];
		int mid=l+r>>1;
		if(y<=mid)return ask(k<<1,l,mid,x,y);
		if(mid<x)return ask(k<<1|1,mid+1,r,x,y);
		return upd(ask(k<<1,l,mid,x,y),ask(k<<1|1,mid+1,r,x,y));
	}
}
using seg::cg;
using seg::ask;
int d[xx],pr[xx];
void out(int x)
{
	if(pr[x])out(pr[x]);
	cout<<x<<" ";
}
int main(){
	n=read();
	for(int i=1;i<=n;i++)e[i].a=lsh1[++tt1]=read(),e[i].b=lsh2[++tt2]=read(),e[i].c=lsh1[++tt1]=read(),e[i].d=lsh2[++tt2]=read();
	sort(lsh1+1,lsh1+tt1+1);
	sort(lsh2+1,lsh2+tt2+1);
	// 
	//cd 
	for(int i=1;i<=n;i++)
	{
		e[i].a=lower_bound(lsh1+1,lsh1+tt1+1,e[i].a)-lsh1;
		v1[e[i].a]++,e[i].a+=v1[e[i].a]-1;
		e[i].c=lower_bound(lsh1+1,lsh1+tt1+1,e[i].c+1)-lsh1-1;
		e[i].b=lower_bound(lsh2+1,lsh2+tt2+1,e[i].b)-lsh2;
		v2[e[i].b]++,e[i].b+=v2[e[i].b]-1;
		e[i].d=lower_bound(lsh2+1,lsh2+tt2+1,e[i].d+1)-lsh2-1;
	}
	for(int i=1;i<=n;i++)cg(1,1,tt1,e[i].a,{e[i].b,i});
	memset(d,0x3f,sizeof(d));
//	for(int i=1;i<=n;i++)cout<<e[i].a<<" "<<e[i].b<<" "<<e[i].c<<" "<<e[i].d<<"!!\n";
//	cout<<tt1<<"!!\n";
	queue<int>q;
	for(int i=1;i<=n;i++)
		if(lsh1[e[i].a]==0&&lsh2[e[i].b]==0)d[i]=0,q.push(i),cg(1,1,tt1,e[i].a,{0,0});
	while(!q.empty())
	{
		int x=q.front();q.pop();
		while(1)
		{
			auto it=ask(1,1,tt1,1,e[x].c);
			if(!it.id||it.mn>e[x].d)break;
			d[it.id]=d[x]+1,pr[it.id]=x,q.push(it.id),cg(1,1,tt1,e[it.id].a,{0,0});
		}
	}
	if(d[n]>1e9)puts("-1");
	else cout<<d[n]+1<<"\n",out(n);
	pc('1',1);
	return 0;
}