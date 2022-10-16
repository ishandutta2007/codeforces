#include<bits/stdc++.h>
#define ll long long
using namespace std;
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
const int xx=1e6+5;
const int mod=1e9+7;
char s[xx];
char c[xx];
ll dp[xx];
ll g[xx];
struct node
{
	int to[26];
	int size;
	int fail;
	int diff;
	int slink;
}e[xx];
int last;
int getfail(int x,int p)
{
	while(c[p]!=c[p-e[x].size-1])x=e[x].fail;return x;
}
int cst;
void add(int x,int p)
{
	int now=getfail(last,p);
	if(e[now].to[x])return last=e[now].to[x],void();
	e[++cst].fail=e[getfail(e[now].fail,p)].to[x];
	e[cst].size=e[now].size+2;
	e[now].to[x]=cst;
	
	e[cst].diff=e[cst].size-e[e[cst].fail].size;
	if(e[cst].diff==e[e[cst].fail].diff)e[cst].slink=e[e[cst].fail].slink;
	else e[cst].slink=e[cst].fail;
	last=cst;
}
int main(){
	cst=1;
	last=1;
	e[1].size=-1;
	e[0].fail=1;
	scanf("%s",s+1);
	int n=strlen(s+1);
	for(int i=1;i<=n;i++)
	{
		if(i&1)c[i]=s[(i+1)/2];
		else c[i]=s[n-i/2+1];
	}
//	cout<<c+1<<endl;
	dp[0]=1;
	for(int i=1;i<=n;i++)
	{
		add(c[i]-'a',i);
		int now=last;
		while(now>1)
		{
			g[now]=dp[i-e[e[now].slink].size-e[now].diff];g[now]>=mod?g[now]-=mod:0;
//			if(i == 4)cout << now << ' ' << e[now].diff << ' ' << e[e[now].slink].size << '\n';
			if(e[now].diff==e [e[now].fail].diff)g[now]+=g[e[now].fail];g[now]>=mod?g[now]-=mod:0;
			if(!(i&1))dp[i]+=g[now];dp[i]>=mod?dp[i]-=mod:0;
			now=e[now].slink;
		}
	}
	cout<<dp[n]<<endl;
	return 0;
}