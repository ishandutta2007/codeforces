#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
//#define INF 0x7fffffff
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
using namespace std;
typedef long long LL;
#define N 524288
#define pi acos(-1)
typedef complex<double> C;
int n,m,i,t,g[N];
C a[N],b[N];
C c[N],d[N],e[N]; 
void FFTinit(){
	for (i=1;i<N;i++) g[i]=g[i>>1]>>1|((i&1)<<18);
}
void FFT(C *a,int f)
{
	int i,j,k,p;
	for (i=0;i<N;i++)
		if (g[i]>i) swap(a[i],a[g[i]]);
	for (i=1;i<N;i<<=1)
	{
		C e(cos(pi/i),f*sin(pi/i));
		for (j=0;j<N;j+=i<<1)
		{
			C w(1,0);
			for (k=0;k<i;k++,w*=e)
			{
				C x=a[j+k],y=w*a[j+k+i];
				a[j+k]=x+y;a[j+k+i]=x-y;
			}
		}
	}
}
int res[N];
int main(){
	int n;
	scanf("%d",&n);
	char c1[100005];
	scanf("%s",c1);
	int t;
	scanf("%d",&t);
	char c2[100005];
	for(int i=0;i<t;i++){
		if(i%2==0)
		c2[i]='a';
		else
		c2[i]='b';
	} 
	c2[t]=0;
	reverse(c2,c2+t);
	MEM(a);
	for(int i=0;i<n;i++){
		if(c1[i]=='?')
		a[i]=0;
		else if(c1[i]=='a')
		a[i]=1;
		else
		a[i]=8;
	}
	MEM(b);
	for(int i=0;i<t;i++){
		b[i]=1;
		//printf("%d",(int)b[i].real());
	}
	FFTinit();
	FFT(a,1);
	FFT(b,1);
	for(int i=0;i<N;i++){
		c[i]=a[i]*b[i];
	}
	MEM(a);
	for(int i=0;i<n;i++){
		if(c1[i]=='?')
		a[i]=0;
		else if(c1[i]=='a')
		a[i]=1;
		else
		a[i]=4;
	}
	MEM(b);
	for(int i=0;i<t;i++){
		if(c2[i]=='a')
		b[i]=1;
		else
		b[i]=2;
		//printf("%d",(int)b[i].real());
	}
	FFT(a,1);
	FFT(b,1);
	for(int i=0;i<N;i++){
		d[i]=a[i]*b[i];
	}
	MEM(a);
	for(int i=0;i<n;i++){
		if(c1[i]=='?')
		a[i]=0;
		else if(c1[i]=='a')
		a[i]=1;
		else
		a[i]=2;
	}
	MEM(b);
	for(int i=0;i<t;i++){
		if(c2[i]=='a')
		b[i]=1;
		else
		b[i]=4;
		//printf("%d",(int)b[i].real());
	}
	FFT(a,1);
	FFT(b,1);
	for(int i=0;i<N;i++){
		e[i]=a[i]*b[i];
	}
	FFT(c,-1);
	FFT(d,-1);
	FFT(e,-1);
	for(int i=0;i<n+t;i++)
		res[i]=(int)(c[i].real()/N+0.5)-2*(int)(d[i].real()/N+0.5)+(int)(e[i].real()/N+0.5);
	pii dp[100005];
	MEM(dp);
	int cnt=0;
	for(int i=0;i<t;i++)
	if(c1[i]=='?')
	cnt++;
	for(int i=t-1;i<n;i++){
	//	printf("%d ",res[i]);
		if(res[i]==0)
		dp[i]=max(dp[i-1],mp(dp[i-t].x+1,dp[i-t].y-cnt));
		else
		dp[i]=dp[i-1];
	//	printf("%d %d %d %d\n",res[i],cnt,dp[i].x,dp[i].y);
		if(c1[i+1]=='?')
		cnt++;
		if(c1[i-t+1]=='?')
		cnt--;
	}
	printf("%d\n",-dp[n-1].y);
}