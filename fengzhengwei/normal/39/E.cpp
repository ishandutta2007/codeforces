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
ll N;
map<pair<int,int> ,int>mp;
bool get(int a,int b)
{
	ll w=1;
	int o=b;
	while(o--)
	{
		w*=a;
		if(w>=N)return 1;// 
	}
	if(b>32)
	{
		puts("Missing");
		exit(0);
	}
	if(b==1&&a>100000)
	{
		return (N-1-a)&1;
	}
	if(mp.find(make_pair(a,b))!=mp.end())return mp[make_pair(a,b)];
	if((!(get(a+1,b))))return mp[make_pair(a,b)]=1,1;
	if((!(get(a,b+1))))return mp[make_pair(a,b)]=1,1;
	return mp[make_pair(a,b)]=0,0;
}
signed main(){
	int a,b;
	a=read(),b=read(),N=read();
	if(get(a,b))
		puts("Masha");
	else puts("Stas");
//	cout<<get(a,b)<<"\n	";
	pc('1',1);
	return 0;
}