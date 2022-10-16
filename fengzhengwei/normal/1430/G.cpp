#include<bits/stdc++.h>
#define ll long long 
#define dd double
#define LL __int128
#define ull unsigned ll
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
#define getchar gc
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
	static char buf[1<<16],*s=buf,*t=(buf+(1<<16));
	(op||((*s++=c)&&(s==t)))&&(fwrite(buf,1,s-buf,stdout),s=buf);
}
void wt(int x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(int x,char op)
{
	if(x<0)pc('-',0),x=-x;
	wt(x),pc(op,0);
}
const int xx=3e5+5;
int f[xx],fn[xx],out[xx],val[xx],sum[xx];
int lb(int x){return x&-x;}
int ans[xx],n,m;
void ad(int x){for(int i=0;i<n;i++)if(x>>i&1)++ans[i];}
int main(){
//	freopen("a.in","r",stdin);
	n=read(),m=read();
	for(int i=1;i<=m;i++)
	{
		int a=read()-1,b=read()-1,c=read();swap(a,b);
		out[a]|=(1<<b),val[a]-=c,val[b]+=c;
	}
	for(int i=1;i<(1<<n);i++)sum[i]=sum[i-lb(i)]+val[__lg(lb(i))];
	memset(f,0x3f,sizeof(f));
	f[0]=0;
	for(int i=0;i<(1<<n);i++)
	{
		int zt=0;
		for(int j=0;j<n;j++)
			if((i&out[j])==out[j]&&(!(i>>j&1)))zt|=(1<<j);
//		cerr<<zt<<" "<<f[i]<<" "<<fn[i]<<"$\n";
		for(int j=zt;j;j=(j-1)&zt)
			if(f[i+j]>f[i]+sum[i])f[i+j]=f[i]+sum[i],fn[i+j]=i;
	}
	int nw=(1<<n)-1;
	while(nw)ad(nw=fn[nw]);
	for(int i=0;i<n;i++)cout<<ans[i]<<" ";
	puts("");
	pc('1',1);
	return 0;
}