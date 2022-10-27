// LUOGU_RID: 90394555
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
char ST;
int n,mod;
#define uLL __uint128_t
struct Fast_mod
{
	ull m,a;
	Fast_mod(const ull M=2):m(M),a(((uLL(1))<<64)/M){}
	ull red(ull x){return x-=(((uLL)x*a)>>64)*m,x>=m?x-m:x;}
}ff;
const int xx=405;
ll ans[xx];
int jiec[xx],ni[xx];
int ksm(int a,int b)
{
	int ans=1;
	while(b)
	{
		if(b&1)ans=ff.red(1ll*ans*a);
		a=ff.red(1ll*a*a),b>>=1; 
	}
	return ans;
}
int C(int n,int m){return ff.red(ff.red(1ll*jiec[n]*ni[m])*ni[n-m]);}
ll xi[xx],f[xx][xx];
char ED;
int main(){
//	cout<<sizeof(f)/1024/1024<<"$\n";// 191 
//	freopen("a.in","r",stdin);
	int T=read();
	mod=read(),ff=Fast_mod(mod);
	
	jiec[0]=1;
	for(int i=1;i<xx;i++)jiec[i]=ff.red(1ll*jiec[i-1]*i);
	ni[xx-1]=ksm(jiec[xx-1],mod-2);
	for(int i=xx-2;i>=0;i--)ni[i]=ff.red(1ll*ni[i+1]*(i+1));
	int lim=400;
	f[0][0]=1;
	for(int i=0;i<lim;i++)
		for(int j=0;j<=lim;j++)
			for(int k=1;(k+j)<=lim;k++)
				f[i+1][j+k]=ff.red(f[i+1][j+k]+f[i][j]*jiec[k]);// 
	for(int i=1;i<=400;i++)
	{
		xi[i]=jiec[i];//  1~t  
		for(int j=1;j<i;j++)
			xi[i]=ff.red(xi[i]+mod-ff.red(xi[j]*jiec[i-j]));
//		cerr<<i<<" "<<xi[i]<<"#\n";
//		if(i<=10)cerr<<i<<" "<<xi[i]<<" xi #\n";
		ll ini=jiec[i];
		for(int j=1;j<i;j++)
		{
			ini=ff.red(ini+mod-ff.red(xi[j]*jiec[i-j]*2));
			// 
		}
//		if(i<=10)cerr<<i<<" "<<ini<<"#\n";
		for(int j=2;j<i;j++)// 1  
			ini=ff.red(ini+mod-ff.red(ans[j]*f[j][i]));
//		if(i<=10)cerr<<i<<" "<<ini<<"#\n";
		ans[i]=ff.red(ans[i]+ini);
		// 
	}
	ans[2]=2;
	while(T--)cout<<ans[read()]<<"\n";
	puts("");
	pc('1',1);
	return 0;
}

}signed main(){return ifzw::main();}