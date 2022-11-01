#include<iostream>
#include<cstdio>
#include<cmath>
#include<queue>
#include<map>
#include<cstring>
#include<ctime>
#include<algorithm>
#define For(i,j,k)  for(register int i=j;i<=k;++i)
#define Dow(i,j,k)  for(register int i=k;i>=j;--i)
#define ll long long
#define mk make_pair
#define pb push_back
#define eps 1e-8
#define pa pair<int,int>
#define fir first
#define sec second
using namespace std;
inline ll read()
{
    ll t=0,f=1;char c=getchar();
    while(c<'0'||c>'9')   {if(c=='-') f=-1;c=getchar();}
    while(c>='0'&&c<='9') t=t*10+c-48,c=getchar();
    return t*f;
}
char s[20001];
int dp[20001][101][2],hav,rt;
int pre[20001],tnxt[20001],poi[200001],nxt[200001],head[20001],flag,cnt,n,q[200001],top,tr[200001],tot,t,p,tmp[201][2];
inline void del(int x){pre[tnxt[x]]=pre[x];tnxt[pre[x]]=tnxt[x];}
inline void add(int x,int y){poi[++cnt]=y;nxt[cnt]=head[x];head[x]=cnt;}
inline void Dfs(int x)
{

	For(i,0,hav)	dp[x][i][1]=1e9,dp[x][i][0]=-1e8;//0->  1-> 
	if(tr[x])	{dp[x][0][1]=dp[x][0][0]=tr[x];return;}
	Dfs(poi[head[x]]);
	For(i,0,hav)	dp[x][i][0]=dp[poi[head[x]]][i][0],dp[x][i][1]=dp[poi[head[x]]][i][1];	//cout<<dp[7][1][0]<<' '<<dp[2][0][0]<<' '<<dp[3][0][0]<<' '<<flag<<endl;
	for(int i=nxt[head[x]];i;i=nxt[i])
	{
		Dfs(poi[i]);
		For(t,0,hav)	tmp[t][1]=1e9,tmp[t][0]=-1e9;
		For(t,0,hav)
			For(j,0,hav)
				{
					if(t+j+(flag^1)<=hav)	tmp[t+j+(flag^1)][1]=min(tmp[t+j+(flag^1)][1],dp[x][t][1]+dp[poi[i]][j][1]);
											tmp[t+j+(flag^1)][0]=max(tmp[t+j+(flag^1)][0],dp[x][t][0]+dp[poi[i]][j][0]);
					if(t+j+(flag)<=hav)		tmp[t+j+(flag)][1]=min(tmp[t+j+(flag)][1],dp[x][t][1]-dp[poi[i]][j][0]);
											tmp[t+j+(flag)][0]=max(tmp[t+j+(flag)][0],dp[x][t][0]-dp[poi[i]][j][1]);
					
				}	
		For(t,0,hav)	dp[x][t][1]=tmp[t][1],dp[x][t][0]=tmp[t][0];
	}
}
inline void Build()
{
	int len=strlen(s+1),num=0,bj=0;
	For(i,1,len)	
	{
		if(isdigit(s[i]))	num=num*10+s[i]-'0',bj=1;
		else
		{
			if(bj)	q[++top]=num;
			num=0;bj=0;
			if(s[i]=='(')	q[++top]=-1;
			else
				if(s[i]==')')q[++top]=-2;
		}
	}
	For(i,1,top)	if(q[i]>=0)	tr[++tot]=q[i],q[i]=tot;
	For(i,1,top)	tnxt[i]=i+1,pre[i]=i-1;
	For(i,1,top)
	{
		if(q[i]==-2)
		{
			int now=pre[i],nod=++tot;del(i);
			while(1)
			{
				int tmp=now;
				now=pre[now];del(tmp);	add(nod,q[tmp]);
				if(q[now]==-1)	{q[now]=tot;break;}

			}
		}
	}
	rt=tot;
}
int main()
{
	scanf("\n%s",s+2);
	s[1]='(';s[strlen(s+1)+1]=')';
	t=read();p=read();
	if(t>p)	flag=1;
	hav=min(t,p);
	Build();
	Dfs(rt);
	cout<<dp[rt][hav][0];	
}