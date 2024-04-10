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
	(op||((*s++=c)&&s==t))&&((fwrite(buf,1,s-buf,stdout)),s=buf);
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
const int xx=5005;
int n,a[xx][3],c[3];
int hnum[3],anum[3];
vector<int>v;
int s[]={500,1000,1500,2000,2500,3000};
int to[]={2,4,8,16,32};
int cg(int x)
{
	for(int i=0;i<5;i++)
	if(n<to[i]*x&&to[i]*x<=n+n)return s[i];
	return s[5];
}
int id[3],sc[3];//id: 
int f[2][95][95][95];//hack 
int vis[xx];
int ans=1e9;
int get(int x)
{
	int fs=0;
	for(int j=0;j<3;j++)
	if(a[x][j]!=0)
		fs+=sc[j]*(250-abs(a[x][j]))/250;
	return fs;
}
int run()
{
	int fs=get(1);
//	cerr<<fs<<"!!!\n";
	for(int j=0;j<3;j++)
		fs+=100*id[j];
//	cerr<<fs<<"!^^\n";
	int res=0;
	for(int i=2;i<=n;i++)
	{
		if(!vis[i])
			res+=(get(i)>fs);
	}
	int sz=v.size();
	for(int i=0;i<=id[0];i++)
	for(int j=0;j<=id[1];j++)
	for(int k=0;k<=id[2];k++)f[1][i][j][k]=1e9;
	f[1][0][0][0]=0;
	for(int s=0;s<sz;s++)
	{
//		cerr<<v[s]<<"\n"; 
		for(int i=0;i<=id[0];i++)
		for(int j=0;j<=id[1];j++)
		for(int k=0;k<=id[2];k++)f[s&1][i][j][k]=1e9;
		
		for(int hk=0;hk<8;hk++)
		for(int i=0;i<=id[0];i++)
		for(int j=0;j<=id[1];j++)
		for(int k=0;k<=id[2];k++)
		{
			if(i-(hk>>0&1)>=0&&j-(hk>>1&1)>=0&&k-(hk>>2&1)>=0)
			{
				int ck=1;
				for(int b=0;b<3;b++)
					if((hk>>b&1)&&a[v[s]][b]>=0)ck=0;
				if(!ck)continue;
				//c 
				for(int b=0;b<3;b++)
					if(hk>>b&1)swap(a[v[s]][b],c[b]);
				f[s&1][i][j][k]=min(f[s&1][i][j][k],f[(s&1)^1][i-(hk>>0&1)][j-(hk>>1&1)][k-(hk>>2&1)]+(get(v[s])>fs));
				for(int b=0;b<3;b++)
					if(hk>>b&1)swap(a[v[s]][b],c[b]);
			}
		}
	}
//	cout<<fs<<" "<<res<<"\n";
	return res+f[(sz&1)^1][id[0]][id[1]][id[2]]+1;
}
void dfs(int x)
{
	if(x==3)
	{
		ans=min(ans,run());
		return;
	}
	for(int i=0;i<6;i++)
	{
		if(cg(anum[x]-hnum[x])<s[i])continue;//hack 
		if(cg(anum[x])>s[i])continue;// 
		int l=0,r=hnum[x],ans=100;// 
		while(l<=r)
		{
			int mid=l+r>>1;
			if(cg(anum[x]-mid)<=s[i])ans=mid,l=mid+1;
			else r=mid-1;
		}
//		cerr<<cg(anum[x]-hnum[x])<<" "<<s[i]<<" "<<id[x]<<" "<<ans<<"!!!\n";
		id[x]=ans,sc[x]=s[i];
		dfs(x+1);
	}
}
int main(){
	n=read();
	for(int j=0;j<3;j++)
	a[1][j]=read(),anum[j]+=(a[1][j]!=0);
	int tt=0;
	for(int i=2;i<=n;i++)
		for(int j=0;j<3;j++)a[i][j]=read(),tt+=(a[i][j]<0),hnum[j]+=(a[i][j]<0),anum[j]+=(a[i][j]!=0);
	for(int i=2;i<=n;i++)
	{
		int vs=0;
		for(int j=0;j<3;j++)
		vs|=(a[i][j]<0);
		if(vs)v.push_back(i);
		vis[i]=vs;
	}
	if(tt>=90)
	{
		puts("1");
		exit(0);
	}
	dfs(0);
	cout<<ans<<"\n";
	pc('1',1);
	return 0;
}