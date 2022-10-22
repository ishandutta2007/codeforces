#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=1e6+100,maxn=1e6;
int a[N],b[N],bk[2][N];ll d[N];
int gcd(int a,int b){
	if(a==0) return b;
	return gcd(b%a,a);
}
int mi(int x,int t,int mod){
	int d=1;
	while(t){
		if(t%2) d=(ll)d*x%mod;
		x=(ll)x*x%mod;t/=2;
	}
	return d;
}
bool cmp(ll n1,ll n2) {return (n1<n2);}
int main()
{
	int n,m;ll K;
	scanf("%d%d%lld",&n,&m,&K);
	memset(bk,0,sizeof(bk));
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),bk[0][a[i]]=i;
	for(int i=1;i<=m;i++) scanf("%d",&b[i]),bk[1][b[i]]=i;
	int t=gcd(n,m);
	int nt=n/t,mt=m/t;
	int e=nt,t2=nt,t3=mt;
	for(int i=2;i<=nt;i++){
		if(e%i==0){
			t2=t2/i*(i-1);
			while(e%i==0) e/=i;
		}
	}
	e=mt;
	for(int i=2;i<=mt;i++){
		if(e%i==0){
			t3=t3/i*(i-1);
			while(e%i==0) e/=i;
		}
	}
	d[0]=0;
	for(int i=1;i<=maxn;i++)
		if(bk[0][i]&&bk[1][i]){
			int x=bk[0][i]-1,y=bk[1][i]-1;
			if(x%t!=y%t) continue;
			int t1=x%t;
			x/=t;y/=t;
			int xx=mi(mt%nt,t2-1,nt),yy=mi(nt%mt,t3-1,mt);
			ll Sum=((ll)xx*mt*x+(ll)yy*nt*y)%((ll)mt*nt);
			Sum=Sum*t+t1;
			d[++d[0]]=Sum+1;
		}
	sort(d+1,d+d[0]+1,cmp);
	ll tt=(K-1)/((ll)nt*mt*t-d[0]);
	ll Ans=tt*nt*mt*t;
	K=(K-1)%((ll)nt*mt*t-d[0])+1;
	d[++d[0]]=(ll)nt*mt*t+1;
	for(int i=1;i<=d[0];i++){
		if(d[i]-i>=K){
			Ans=Ans+K+i-1;
			break;
		}
	}
	printf("%lld\n",Ans);
	return 0;
}