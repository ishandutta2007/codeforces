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
const int xx=25;
int n;
struct nod{int id,a,b;bool operator<(const nod&w)const{return a<w.a;};}e[xx];
int main(){
	n=read();
	for(int i=1;i<=n;i++)e[i].id=i,e[i].a=read();
	sort(e+1,e+n+1);
	for(int i=2;i<=n;i++)e[i].b=e[i-1].a;
	e[1].b=e[n].a;
	sort(e+1,e+n+1,[&](nod a,nod b){return a.id<b.id;});
	for(int i=1;i<=n;i++)cout<<e[i].b<<" ";
	puts("");
	pc('1',1);
	return 0;
}