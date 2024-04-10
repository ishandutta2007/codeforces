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
void wts(int x,char c)
{
	if(x<0)pc('-',0),x=-x;
	wt(x),pc(c,0);
}
//st 23:20 
const int xx=1e5+5;
char s[xx];
// 
struct node{int next,to;}e[xx<<1];
int cnt,cst,h[xx];
void add(int x,int y)
{
	cnt++;
	e[cnt].next=h[x];
	h[x]=cnt;
	e[cnt].to=y;
}
int f[xx],v[xx],sz[xx];
int tmn[10004],tmx[10004];
vector<int>dpmn[10004],dpmx[10004];
void dfs(int x)
{
	if(v[x]){dpmn[x].push_back(v[x]);dpmx[x].push_back(v[x]);return;}//0 
	sz[x]=-1;
	for(int i=h[x];i;i=e[i].next)
	{
		dfs(e[i].to);
		if(sz[x]==-1)
			swap(dpmn[x],dpmn[e[i].to]),
			swap(dpmx[x],dpmx[e[i].to]);
		else 
		{
			for(int j=0;j<=sz[x]+1+sz[e[i].to];j++)tmn[j]=1e9,tmx[j]=-1e9;
			for(int j=0;j<=sz[x];j++)
			{
				for(int k=0;k<=sz[e[i].to];k++)
				{
					tmx[j+k+1]=max(tmx[j+k+1],dpmx[x][j]+dpmx[e[i].to][k]);
					tmn[j+k+1]=min(tmn[j+k+1],dpmn[x][j]+dpmn[e[i].to][k]);
					tmx[j+k]=max(tmx[j+k],dpmx[x][j]-dpmn[e[i].to][k]);
					tmn[j+k]=min(tmn[j+k],dpmn[x][j]-dpmx[e[i].to][k]);
				}
			}
			dpmx[x].resize(sz[x]+1+sz[e[i].to]+1);
			dpmn[x].resize(sz[x]+1+sz[e[i].to]+1);
			for(int j=0;j<=sz[x]+1+sz[e[i].to];j++)dpmx[x][j]=tmx[j],dpmn[x][j]=tmn[j];
		}
		sz[x]++;
		sz[x]+=sz[e[i].to];
	}
//	for(int j=0;j<=sz[x];j++)cout<<x<<" "<<j<<" "<<dpmx[x][j]<<" "<<dpmn[x][j]<<"\n";
}
signed main(){
	scanf("%s",s+1);
	s[0]='(';
	s[strlen(s)]=')';
	int nt=0,len=strlen(s),nnd=0;
	while(nt!=len)
	{
		if(s[nt]=='(')
			f[++cst]=nnd,nnd=cst,nt++;//nnd 
		else if(s[nt]==')')nnd=f[nnd],nt++;
		else if(s[nt]=='?')nt++;
		else f[++cst]=nnd,v[cst]=s[nt]-'0',nt++;
	}
	for(int i=cst;i>=1;i--)if(f[i])add(f[i],i);
	dfs(1);
	int a=read(),b=read();
	cout<<dpmx[1][a]<<"\n";
	pc('1',1);
	return 0;
}