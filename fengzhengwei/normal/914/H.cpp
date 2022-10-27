// LUOGU_RID: 90479923
#include<bits/stdc++.h>
namespace ifzw{
#define ll long long 
#define dd double
#define LL __int128
#define ld long double
#define ull unsigned ll 
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
#define getchar gc
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
const int xx=2e2+5;
char ST;
#define uLL __uint128_t
struct Fm
{
	ull m,a;
	Fm(ull M=2):m(M),a((uLL(1)<<64)/M){}
	ull re(ull x){return x-=((uLL(x)*a)>>64)*m,x>=m?x-m:x;}
}ff;
int n,d,m;
int c[xx][xx],g[xx][xx];
ll t[xx];
void ad(int &a,ll b){(a=ff.re(a+b));}
char ED;
int main(){
//	cout<<sizeof(f)/1024/1024<<"$\n";// 191 
//	freopen("a.in","r",stdin);
	n=read(),d=read(),m=read(),ff=Fm(m);
	if(d==1&&n==2)cout<<4<<"\n",exit(0);
	else if(d==1)puts("0"),exit(0);
	for(int i=0;i<xx;i++)c[i][0]=1;
	for(int i=1;i<xx;i++)
		for(int j=1;j<=i;j++)c[i][j]=ff.re(1ll*c[i-1][j]+c[i-1][j-1]);
	g[1][0]=1,t[1]=1;
	
	for(int i=2;i<xx;i++)
	{
		for(int j=1;j<=d;j++)
			for(int k=1;k<i;k++)
				ad(g[i][j],ff.re(g[i-k][j-1]*t[k])*c[i-2][k-1]);
//		for(int j=0;j<=d;j++)cerr<<i<<" "<<j<<" "<<g[i][j]<<"!\n";
		for(int j=0;j<d;j++)t[i]+=g[i][j];
		t[i]=ff.re(t[i]);
	}
	
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int d1=0;d1<=d;d1++)
		{
			if(d1==1)continue;
			for(int d2=0;(d2+d1)<=d;d2++)
				ad(ans,1ll*g[i][d1]*g[n+1-i][d2]);
		}
	}
	
	cout<<ff.re(1ll*ans*n*(n-1)*2)<<"\n";
	pc('1',1);
	return 0;
}

}signed main(){return ifzw::main();}