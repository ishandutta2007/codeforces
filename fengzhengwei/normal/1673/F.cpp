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
	pc(x%10+'0',0);
}
void wts(int x,char op)
{
	if(x<0)x=-x,pc('-',0);
	wt(x),pc(op,0);
}
const int xx=1e6+5;
int n,k,h[xx],l[xx],th,tl,hid[xx],lid[xx];
int glm[xx],tt;
signed main(){
	for(int i=0;i<=16;i+=2)
		h[++th]=(1<<i),l[++tl]=(1<<(i+1));
	int re=0,ce=0;
	for(int i=1;i<=th;i++)re+=h[i];
	for(int i=1;i<=tl;i++)ce+=l[i];
	for(int i=1;i<=7;i++)
	{
		int len=tt;
		glm[++tt]=i;
		for(int j=1;j<=len;j++)glm[++tt]=glm[j];
	}
	int now=0;
	h[0]=0;
	for(int i=1;i<=tt;i++)
		now^=h[glm[i]],hid[now]=i;
	now=0;l[0]=0;
	for(int i=1;i<=tt;i++)
		now^=l[glm[i]],lid[now]=i;
	n=read(),k=read();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<n;j++)
			cout<<h[glm[j]]<<" ";
		puts("");
	}
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<=n;j++)
			cout<<l[glm[i]]<<" ";
		puts("");
	}
	fflush(stdout);
//	cerr<<re<<" "<<ce<<"$%\n";
	int nval=0;
	while(k--)
	{
		nval^=read();
		cout<<lid[nval&ce]+1<<" "<<hid[nval&re]+1<<"\n";
//		cout<<hid[nval&re]+1<<" "<<lid[nval&ce]+1<<"\n";
		fflush(stdout);
	}
	pc('1',1);
	return 0;
}