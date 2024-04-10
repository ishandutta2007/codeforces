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
const int xx=2e5+5;
ll n,k,mod;
ll c[105][105],h[105][105],all[105][105];
//allnk 
//hnn>0k1 
ll pw[200005];
ll ksm(ll a,ll b)
{
	if(a==2)return pw[b];
	ll ans=1;
	while(b)
	{
		if(b&1)ans*=a,ans%=mod;
		a*=a,a%=mod,b>>=1;
	}
	return ans;
}
//A 
ll A(ll n,ll m)
{
	ll ans=1;
	for(int i=1;i<=m;i++)ans*=(n-i+1),ans%=mod;
	return ans;
}
ll get(int a){return a&1?mod-1:1;}
void init()
{
	
//	puts("ASD");
	for(int N=1;N<=n;N++)
	{
		for(int K=0;K<=k;K++)
		{
			for(int i=0;i<=K;i++)
			h[N][K]+=A(ksm(2,i)-1,N)*get(K-i)%mod*c[K][i]%mod,
			all[N][K]+=ksm(2,N*i)*get(K-i)%mod*c[K][i]%mod;
			h[N][K]%=mod,all[N][K]%=mod;
//	cout<<all[N][0]<<" "<<c[K][0]<<" "<<ksm(2,N*i)<<" "<<<"@#$\n";;
		}
	}
}
ll g[105][105];//nk1bad+best 
int main(){
	n=read(),k=read(),mod=read();
	pw[0]=1;
	for(int i=1;i<=200000;i++)pw[i]=pw[i-1]*2%mod;
	for(int i=0;i<=100;i++)c[i][0]=1;
	for(int i=1;i<=100;i++)
		for(int j=1;j<=i;j++)c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
	init();
	all[0][0]=1; 
	for(int N=0;N<=n;N++)
	{
		for(int K=0;K<=k;K++)
		{
			for(int i=0;i<N;i++)
			{
				for(int j=0;j<K;j++)
				{
					//best 
					if((n&1)&&N==n&&i==N-1)continue;
					g[N][K]+=c[N][i]*c[K][j]%mod*ksm(2,j*(N-i))%mod*(all[i][j]-g[i][j]+mod)%mod*h[N-i][K-j]%mod;
					g[N][K]%=mod;
					//3,0 0,3 
//					cout<<g[N][K]<<" "<<N<<" "<<K<<' '<<i<<" "<<j<<" "<<all[i][j]<<"\n";
				}
			}
		}
	}
//	cout<<all[n][0]<<"  1\n";
//	cout<<all[n][1]<<"  1\n";
//	cout<<all[n][2]<<"  1\n";
//	puts("");
//	cout<<g[n][0]<<"  1\n";
//	cout<<g[n][1]<<"  1\n";
//	cout<<g[n][2]<<"  1\n";
//	puts("");
//	cout<<h[1][1]<<"  1\n";
//	cout<<h[n][0]<<"  1\n";
//	cout<<h[n][1]<<"  1\n";
//	cout<<h[n][2]<<"  1\n";
//	cout<<g[n][0]<<"  1\n";
//	cout<<g[n][1]<<"  1\n";
//	cout<<all[n][2]<<"  1\n";
//	cout<<g[n][2]<<"  1\n";
	ll ans=0;
	for(int i=0;i<=k;i++)
		ans+=(all[n][i]-g[n][i]+mod)*c[k][i]%mod;
	ans%=mod;
	cout<<ans<<"\n";
	pc('1',1);
	return 0;
}