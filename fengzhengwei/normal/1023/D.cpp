#include<bits/stdc++.h>
#define ll long long
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
const int xx=2e5+5;
vector<int>v[xx];
int mn[xx][21];
int ask(int l,int r){int k=log2(r-l+1);return min(mn[l][k],mn[r-(1<<k)+1][k]);}
int a[xx];
vector<int>c[xx];
int main(){
	int n=read(),m=read();
	//0 
	int vs=0;
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		if(a[i])v[a[i]].push_back(i);
		else vs=1;
	}
	for(int i=1;i<=n;i++)if(a[i]==m)vs=1;
	if(!vs)puts("NO"),exit(0);
	for(int i=1;i<=n;i++)if(a[i])mn[i][0]=a[i];else mn[i][0]=1e9;
	for(int j=1;j<=20;j++)
	for(int i=1;i<=n;i++)
		if(i+(1<<(j-1))<=n)mn[i][j]=min(mn[i][j-1],mn[i+(1<<j-1)][j-1]);
	for(int i=1;i<=m;i++)
	{
		if(v[i].size())
		{
			if(ask(v[i][0],v[i][v[i].size()-1])<i)
				puts("NO"),exit(0);
		}
	}
	puts("YES");
	for(int i=m;i>=2;i--)
	{
		if(v[i].size())
		{
			c[v[i][0]].push_back(i);
			c[v[i][v[i].size()-1]+1].push_back(i);
		}
		else if(i==m)
		{
			for(int j=1;j<=n;j++)
			{
				if(a[j]==0)
				{
					c[j].push_back(i);
					c[j+1].push_back(i);
					break;
				}
			}
		}
	}
	c[1].push_back(1);
	c[n+1].push_back(1);
	set<int>s;
	for(int i=1;i<=n;i++)
	{
		for(auto it:c[i])
		{
			if(s.find(it)!=s.end())s.erase(it);
			else s.insert(it);
		}
		cout<<*--s.end()<<" ";
	}
	puts("");
	pc('1',1);
	return 0;
}