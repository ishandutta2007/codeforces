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
void wts(int x,char op)
{
	if(x<0)pc('-',0),x=-x;
	wt(x);pc(op,0);
}
const int xx=1e5+5;
int n,m,a[xx],t[xx],l,r;
ll ans,f[xx],g[xx];
void ad(int k){ans+=t[a[k]],t[a[k]]++;}
void er(int k){t[a[k]]--;ans-=t[a[k]];}
const ll inf=1e18;
ll re=0;
ll w(int x,int y)
{
	if(x>y)return inf+inf;
	while(r<y)ad(++r);//,puts("A");
	while(l>x)ad(--l);//,puts("B");
	while(r>y)er(r--);//,puts("C");
	while(l<x)er(l++);//,puts("D");
	return ans+f[x-1];
}
void ef(int l,int r,int L,int R)
{
	if(l>r)return;
	if(L==R)
	{
	    re+=(r-L+1);
		for(int i=l;i<=r;i++)g[i]=w(L,i);
		return ;
	}
	int mid=l+r>>1,zy=L;
	re+=(mid-L+1);
	ll zval=w(L,mid);
	for(int i=L;i<=R;i++)
		if(w(i,mid)<zval)zval=w(i,mid),zy=i;
	g[mid]=zval;
	ef(l,mid-1,L,zy);
	ef(mid+1,r,zy,R);
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	r=0,l=1;
	memset(g,0x3f,sizeof(g));
	g[0]=0;
//	cout<<w(1,1)<<"ASDASD\n";
//	cout<<t[1]<<" "<<l<<" "<<r<<" "<<a[1]<<"!DASD\n";
//	exit(0);
	for(int j=1;j<=m;j++)
	{
		for(int i=0;i<=n;i++)f[i]=g[i],g[i]=inf;
		ef(1,n,1,n);
//		for(int i=0;i<=n;i++)cout<<i<<" "<<g[i]<<" "<<w(1,1)<<" "<<ans<<" "<<t[1]<<"\n";
	}
	cerr<<re<<"!!\n";
	cout<<g[n]<<"\n";
	pc('1',1);
	return 0;
}