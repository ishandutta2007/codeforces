#include<bits/stdc++.h>
#define ll long long 
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
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
void wts(int x,char c)
{
	if(x<0)x=-x,pc('-',0);
	wt(x);pc(c,0);
}
const int xx=200005;
int n,k,vis[xx],re[xx],mx;
int main(){
	n=read(),k=read();
	vector<int>res;
	set<int>s;
	for(int i=1;i<=k;i++)
	{
		int o=read();
		if(o<mx)
		{
			puts("-1");
			exit(0);
		}
		s.insert(o);
		if(s.find(o)!=s.begin())mx=max(mx,*--s.find(o));
		res.push_back(o);
		vis[o]=1;
	}
	for(int i=1;i<=n;i++)if(!vis[i]&&i<mx){puts("-1");exit(0);}
	for(auto it:res)cout<<it<<" ";
	vis[n+1]=1;
	int x=1,last=1;
	while(x!=n+2)
	{
		if(vis[x])
		{
			for(int j=x-1;j>=last;j--)cout<<j<<" ";
			last=x+1;
			x++;
		}
		else x++;
	}
	pc('1',1);
	return 0;
}