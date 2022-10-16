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
int n;
const int xx=1e5+5;
struct node{int x,y;}e[xx];
vector<int>t[4];
void run()
{
	for(int i=0;i<4;i++)t[i].clear();
	for(int i=1;i<=n;i++)
		t[((e[i].x&1)<<1)+(e[i].y&1)].push_back(i);
	if(t[0].size()+t[3].size()&&t[1].size()+t[2].size())
	{
		cout<<t[0].size()+t[3].size()<<"\n";
		for(auto it:t[0])cout<<it<<" ";
		for(auto it:t[3])cout<<it<<" ";exit(0);
	}
	if(t[0].size()&&t[3].size())
	{
		cout<<t[0].size()<<"\n";
		for(auto it:t[0])cout<<it<<" ";exit(0);
	}
	if(t[1].size()&&t[2].size())
	{
		cout<<t[1].size()<<"\n";
		for(auto it:t[1])cout<<it<<" ";exit(0);
	}
	for(int i=1;i<=n;i++)
	{
		e[i].x-=e[i].x&1;
		e[i].x/=2;
		e[i].y-=e[i].y&1;
		e[i].y/=2;
	}
	run();
}
int main(){
	n=read();
	for(int i=1;i<=n;i++)
		e[i].x=read(),e[i].y=read();
	run();
	pc('1',1);
	return 0;
}