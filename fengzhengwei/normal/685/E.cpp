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
void wt(ll x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(ll x,char c)
{
	if(x<0)pc('-',0),x=-x;
	wt(x),pc(c,0);
}
const int xx=200005;
int n,m,q,A[xx],B[xx];
int to[1005][1005];//abl 
struct nod
{
	int a,b,S,T,id;//ST 
	bool operator<(const nod&w)const{return T<w.T;}
}s[xx];
void in(int x)
{
	for(int i=1;i<=n;i++)
		to[i][B[x]]=max(to[i][B[x]],min(to[i][A[x]],x)),to[i][A[x]]=max(to[i][A[x]],min(to[i][B[x]],x));;
}
int ans[xx];
int main(){
	n=read(),m=read(),q=read();
	for(int i=1;i<=m;i++)A[i]=read(),B[i]=read();
	memset(to,-0x3f,sizeof(to));
	for(int i=1;i<=n;i++)to[i][i]=1e9;
	for(int i=1;i<=q;i++)
		s[i].S=read(),s[i].T=read(),s[i].a=read(),s[i].b=read(),s[i].id=i;
	sort(s+1,s+q+1);
	int now=1;
	for(int i=1;i<=q;i++)
	{
		while(now<=s[i].T)in(now++);
		if(s[i].a==s[i].b)ans[s[i].id]=1;//
		else if(to[s[i].a][s[i].b]>=s[i].S)ans[s[i].id]=1;
		else ans[s[i].id]=0;
	}
	for(int i=1;i<=q;i++)if(ans[i])puts("Yes");else puts("No");
	pc('1',1);
	return 0;
}