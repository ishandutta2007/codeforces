#include<bits/stdc++.h>
#define ll long long
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
	wt(x);pc(op,0);
}
const int xx=5e5*3+5;
int n;
char s[xx];
struct nod{int link,size,to[26];}e[xx];
int cst,last,id[xx];
int add(int x)
{
//	cerr<<cst<<"\n";
	int now=++cst,p=last;e[now].size=e[p].size+1,last=now;
	while(p&&!e[p].to[x])e[p].to[x]=now,p=e[p].link;
	if(!p)e[now].link=1;
	else 
	{
		int q=e[p].to[x];
		if(e[p].size+1==e[q].size)e[now].link=q;
		else 
		{
			int s=++cst;
			e[s].size=e[p].size+1;
			for(int i=0;i<26;i++)e[s].to[i]=e[q].to[i];
			e[s].link=e[q].link;
			e[now].link=e[q].link=s;
			while(p&&e[p].to[x]==q)e[p].to[x]=s,p=e[p].link;
		}
	}
	return now;
}
// 
namespace T
{
	struct node{int next,to;}e[xx<<1];
	int cnt,h[xx];
	void add(int x,int y)
	{
		cnt++;
		e[cnt].next=h[x];
		h[x]=cnt;
		e[cnt].to=y;
	}
	int size[xx],dfx[xx],cst;
	void dfs(int x)
	{
		size[x]=1,dfx[x]=++cst;
		for(int i=h[x];i;i=e[i].next)dfs(e[i].to),size[x]+=size[e[i].to];
	}
	int mx[xx<<2];
	void cg(int k,int l,int r,int x,int y)
	{
		if(l==r)return mx[k]=max(mx[k],y),void();
		int mid=l+r>>1;
		if(x<=mid)cg(k<<1,l,mid,x,y);
		else cg(k<<1|1,mid+1,r,x,y);
		mx[k]=max(mx[k<<1],mx[k<<1|1]);
	}
	int ask(int k,int l,int r,int x,int y)
	{
//		cout<<x<<" "<<y<<" "<<l<<" "<<r<<" "<<mx[k]<<"!!!\n";
		if(y<=0)return 0;
		if(x<=l&&r<=y)return mx[k];
		int mid=l+r>>1;
		if(y<=mid)return ask(k<<1,l,mid,x,y);
		if(mid<x)return ask(k<<1|1,mid+1,r,x,y);
		return max(ask(k<<1,l,mid,x,y),ask(k<<1|1,mid+1,r,x,y));
	}
	void Cg(int x,int y){cg(1,1,cst,dfx[x],y);}//x 
	int Ask(int x){return ask(1,1,cst,dfx[x],dfx[x]+size[x]-1);}
}
using T::Cg;
using T::Ask;
int dp[xx];
signed main(){
//	freopen("a.in","r",stdin);
	cst=last=1;
	n=read();
	scanf("%s",s+1);
	//dp 
	for(int i=n;i>=1;i--)id[i]=add(s[i]-'a');
//	cerr<<cst<<"\n";
//	exit(0);
	for(int i=1;i<=cst;i++)
	{
		T::add(e[i].link,i);
		e[i].to[0]=e[i].link;
	}
	for(int j=1;j<=22;j++)
	for(int i=1;i<=cst;i++)e[i].to[j]=e[e[i].to[j-1]].to[j-1];
	T::dfs(1);
	int mx=0;
	for(int i=n;i>=1;i--)
	{
		dp[i]=dp[i+1]+1;
		while(dp[i]>1)
		{
			int now=id[i];
//			if(i==17)cout<<now<<"!!!\n";
//			if(i==17)cout<<e[now].to[0]<<"!!!\n";
//			if(i==17)cout<<e[now].to[1]<<"!!!\n";
			for(int j=21;j>=0;j--)
			{
				if(e[now].to[j]&&e[e[now].to[j]].size>=dp[i]-1)
				now=e[now].to[j];
			}
//			if(i==17)cout<<now<<"!!!\n";
//			if(i==1)cout<<now<<" "<<dp[i]<<" "<<id[2]<<" "<<e[id[2]].to[0]<<" "<<Ask(now)<<" "<<T::dfx[now]<<" "<<T::size[now]<<" "<<e[now].size<<"!!\n";
//			now=e[now].to[0];
//			if(i==17)cout<<now<<" "<<dp[i]<<" "<<id[17]<<" "<<e[28].to[0]<<" "<<e[28].size<<" "<<e[id[2]].to[0]<<" "<<Ask(now)<<" "<<T::dfx[now]<<" "<<T::size[now]<<" "<<e[now].size<<"!!\n";
			if(Ask(now)>=dp[i]-1)break;
			now=id[i+1];
			for(int j=21;j>=0;j--)
			{
				if(e[now].to[j]&&e[e[now].to[j]].size>=dp[i]-1)
				now=e[now].to[j];
			}
//			now=e[now].to[0];
			if(Ask(now)>=dp[i]-1)break;
			dp[i]--;
			Cg(id[i+dp[i]],dp[i+dp[i]]);
			//dpmx 
		}
		mx=max(mx,dp[i]);
//		cout<<i<<" "<<dp[i]<<"!!\n";
	}
	cout<<mx<<"\n";
	pc('1',1);
	return 0;
}