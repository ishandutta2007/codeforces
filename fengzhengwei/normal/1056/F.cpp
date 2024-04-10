// LUOGU_RID: 91509907
#include<bits/stdc++.h>
namespace ifzw{
#define ll long long 
#define dd double
#define LL __int128
#define ld long double
#define ull unsigned ll 
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
const int xx=105;
struct nod{int a,p;bool operator<(const nod&w)const{return a>w.a;};}e[xx];
dd f[2][xx][xx*10],pw[xx],C,T;
void ad(dd&a,dd b){a=min(a,b);}
int main(){
	pw[0]=1,pw[1]=1/0.9;
	for(int i=2;i<xx;i++)pw[i]=pw[i-1]*pw[1];
	int Ts=read();
	while(Ts--)
	{
		int n=read();
		scanf("%lf",&C),scanf("%lf",&T);
		for(int i=1;i<=n;i++)
			e[i].a=read(),e[i].p=read();
		sort(e+1,e+n+1);
//		for(int i=1;i<=n;i++)cerr<<e[i].a<<" "<<e[i].p<<"$\n";
		memset(f,0,sizeof(f));
		for(int i=0;i<=1;i++)
			for(int j=0;j<xx;j++)
				for(int k=0;k<xx*10;k++)f[i][j][k]=1e18;
		f[0][0][0]=0;
		for(int i=0;i<n;i++)
			for(int j=0;j<=i;j++)
				for(int k=0;k<=j*10;k++)
					ad(f[i+1&1][j+1][k+e[i+1].p],f[i&1][j][k]+e[i+1].a*pw[j+1]),
					ad(f[i+1&1][j][k],f[i&1][j][k]),
					f[i&1][j][k]=1e18;
		int ans=0;
		for(int k=n*10;k>=0;k--)
		{
			for(int j=0;j<=n;j++)
			{
				dd lim=T-j*10;
				if(lim<0)continue;
				dd W=f[n&1][j][k]*C,use=0,li=sqrt(W);
				if(li<1)use=W+1;// 
				else use=2*li;
				dd ty=(use-1)/C;
//				if(W!=1e18)cerr<<k<<" "<<W<<" "<<j<<" "<<lim<<" "<<ty<<"#\n";
				if(ty<=lim){ans=k;break;}
			}
			if(ans>0)break;
		}
		cout<<ans<<"\n";
	}
	pc('1',1);
	return 0;
}



}signed main(){return ifzw::main();}