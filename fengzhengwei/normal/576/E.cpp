#include<bits/stdc++.h>
#define ll long long
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return*s++;}
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
const int xx=5e5+5;
int n,m,k,q,uu[xx],vv[xx],fa[52][xx],sum[52][xx],size[52][xx],t[xx],nc[xx],nxt[xx];
void init()
{
	for(int i=1;i<=50;i++)
		for(int j=1;j<=n;j++)fa[i][j]=j,sum[i][j]=0,size[i][j]=1;
}
struct pr{int x,y;pr(int a,int b):x(a),y(b){}pr(){}};
pr find(int col,int x)//  
{
	if(fa[col][x]==x)return pr(x,0);
	pr a=find(col,fa[col][x]);a.y^=sum[col][x];
	return a;
}
vector<pr>v[xx<<2];//col 
pr stk[xx];//id 
int top;
void merge(int col,int x,int y)
{
	pr a=find(col,x),b=find(col,y);
	if(a.x==b.x)return;// 
	if(size[a.x]<size[b.x])swap(a,b);
	sum[col][b.x]=1^a.y^b.y,size[col][a.x]+=size[col][b.x],fa[col][b.x]=a.x;
	stk[++top]=pr(b.x,col);
}
void hy()
{
	int x=stk[top].x,col=stk[top].y;
	size[col][fa[col][x]]-=size[col][x];
	fa[col][x]=x;sum[col][x]=0;top--;
}
void cover(int k,int l,int r,int x,int y,int id,int col)
{
	if(x>y)return;
	if(x<=l&&r<=y)return v[k].push_back(pr(id,col));
	int mid=l+r>>1;
	if(x<=mid)cover(k<<1,l,mid,x,y,id,col);
	if(mid<y)cover(k<<1|1,mid+1,r,x,y,id,col);
}
pr qu[xx];
void ask(int k,int l,int r)
{
	int now=top;
	for(auto it:v[k])merge(it.y,uu[it.x],vv[it.x]);
	if(l==r)
	{
		int x=uu[qu[l].x],y=vv[qu[l].x];
		pr a=find(qu[l].y,x),b=find(qu[l].y,y);
		if(a.x!=b.x||(a.y^b.y)){puts("YES");nc[qu[l].x]=qu[l].y;cover(1,1,q,l+1,nxt[l],qu[l].x,qu[l].y);}
		else 
		{
			puts("NO");
			if(nc[qu[l].x])cover(1,1,q,l+1,nxt[l],qu[l].x,nc[qu[l].x]);
		}
		while(top!=now)hy();
		return;
	}
	int mid=l+r>>1;
	ask(k<<1,l,mid);
	ask(k<<1|1,mid+1,r);
	while(top!=now)hy();
}
signed main(){
	n=read(),m=read(),k=read(),q=read();init();
	for(int i=1;i<=m;i++)uu[i]=read(),vv[i]=read(),t[i]=q;
	for(int i=1;i<=q;i++)qu[i].x=read(),qu[i].y=read();
	for(int i=q;i>=1;i--)nxt[i]=t[qu[i].x],t[qu[i].x]=i;
	ask(1,1,q);
	return 0;
}