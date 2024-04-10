#include<bits/stdc++.h>
#define ll long long
#define dd double
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
struct pt
{
	int a,b;
	bool operator<(const pt&w)const{return a==w.a?b<w.b:a<w.a;}
}e[5];
vector<pair<int,int> >ans;
void out()
{
	cout<<ans.size()<<"\n";
	for(auto it:ans)cout<<it.first<<" "<<it.second<<"\n";
	exit(0);
}
int main(){
	for(int i=1;i<=3;i++)e[i].a=read(),e[i].b=read();
	sort(e+1,e+4);
	if(e[1].a==e[2].a&&e[1].a==e[3].a)
	{
		for(int i=e[1].b;i<=e[3].b;i++)
			ans.push_back(make_pair(e[1].a,i));
		out();
	}
	if(e[1].b>=e[2].b)
	{
		for(int i=e[1].a;i<=e[2].a;i++)ans.push_back(make_pair(i,e[1].b));
		for(int i=e[1].b-1;i>=e[2].b;i--)
			ans.push_back(make_pair(e[2].a,i));
	}
	if(e[1].b<e[2].b)
	{
		for(int i=e[1].a;i<=e[2].a;i++)ans.push_back(make_pair(i,e[1].b));
		for(int i=e[1].b+1;i<=e[2].b;i++)
			ans.push_back(make_pair(e[2].a,i));
	}
	if(e[3].b>max(e[1].b,e[2].b))
	{
		for(int i=e[3].b;i>max(e[1].b,e[2].b);i--)
			ans.push_back(make_pair(e[3].a,i));
		e[3].b=max(e[1].b,e[2].b);
	}
	if(e[3].b<min(e[1].b,e[2].b))
	{
		for(int i=e[3].b;i<min(e[1].b,e[2].b);i++)
			ans.push_back(make_pair(e[3].a,i));
		e[3].b=min(e[1].b,e[2].b);
	}
	for(int i=e[3].a;i>e[2].a;i--)
		ans.push_back(make_pair(i,e[3].b));
	out();
	pc('1',1);
	return 0;
}