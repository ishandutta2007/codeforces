#include<bits/stdc++.h>
#define ll long long
#define dd double
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
const int xx=2e5+5;
int n,m;
struct nod{int to[26];}e[xx];
char s[xx];
int cst,last;
int g(int &a){return a?a:(a=++cst);}
void in()
{
	int len=strlen(s+1);
	last=1;
	for(int i=1;i<=len;i++)last=g(e[last].to[s[i]-'a']);
}
// 
int cr[xx],_cr[xx];
void dfs(int x)
{
	int vs=1;
	for(int i=0;i<26;i++)if(e[x].to[i])dfs(e[x].to[i]),cr[x]|=(!cr[e[x].to[i]]),_cr[x]|=(!_cr[e[x].to[i]]),vs=0;
	if(vs)cr[x]=0,_cr[x]=1;
}
signed main(){
	last=cst=1;
	n=read(),m=read();
	for(int i=1;i<=n;i++)scanf("%s",s+1),in();
	dfs(1);
	if(cr[1]&&_cr[1])puts("First");
	else if(!cr[1])puts("Second");
	else if(!_cr[1])
	{
		if(m&1)puts("First");
		else puts("Second");
	}
	pc('1',1);
	return 0;
}