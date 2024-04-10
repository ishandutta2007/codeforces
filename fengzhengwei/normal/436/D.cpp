#include<bits/stdc++.h>
#define ll long long
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
void wts(int x,char c)
{
	if(x<0)pc('-',0),x=-x;
	wt(x),pc(c,0);
}
int n,m;
const int xx=1e5+5;
int a[xx],v[xx];
struct nod{int l,r,sz;}e[xx];
int f[xx],L[xx],R[xx],s[xx]; 
signed main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=m;i++)v[i]=read();
	sort(a+1,a+n+1),sort(v+1,v+m+1);
	int tt=0;
	for(int i=1;i<=n;i++)
	{
		int j=i;
		while(a[j+1]==a[j]+1)j++;
		e[++tt].l=a[i];
		e[tt].r=a[j];
		e[tt].sz=a[j]-a[i]+1;
		i=j;//
	}
	for(int i=1;i<=m;i++)L[i]=tt+1,R[i]=tt+1;
	int l=0;
	for(int i=1;i<=tt;i++)s[i]=s[i-1]+e[i].sz;
	for(int i=1;i<=tt;i++)
	{
		f[i]=max(f[i],f[i-1]);
		while(v[l+1]<=e[i].r&&(l+1)<=m)l++;
		//<=e[i].r 
		int mx=f[i-1];//0 
		for(int j=1;j<=l;j++)
		{
			while(L[j]&&v[j]<e[i].r-(s[i]-s[L[j]-1])+1)L[j]--;//
			if(L[j])mx=max(mx,f[L[j]-1]+l-j+1);
		}
		f[i]=max(f[i],mx);
		for(int j=l+1;j<=m;j++)
		{
			while(v[j]<=e[i].l+(s[R[j]-1]-s[i-1])-1)R[j]--;//
			if(R[j]!=tt+1)f[R[j]]=max(f[R[j]],mx+j-l);//
//		cout<<i<<" "<<f[i]<<" "<<l<<" "<<v[l]<<" "<<R[j]<<" q "<<mx<<"\n";
		}
	}
	cout<<f[tt]<<"\n";
	pc('1',1);
	return 0;
}