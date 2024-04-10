#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int mod=998244353;
const int N=3e5+100,maxn=3e5;
int a[N],fl[N],nf[N];
int mi(int x,int t){
	int d=1;
	while(t){
		if(t%2) d=(ll)d*x%mod;
		x=(ll)x*x%mod;t/=2;
	}
	return d;
}
int ni(int x) {return mi(x,mod-2);}
bool cmp(int n1,int n2) {return (n1<n2);}
int main()
{
	fl[0]=1;for(int i=1;i<=maxn;i++) fl[i]=(ll)fl[i-1]*i%mod;
	nf[maxn]=ni(fl[maxn]);for(int i=maxn-1;i>=0;i--) nf[i]=(ll)nf[i+1]*(i+1)%mod;
	int n;scanf("%d",&n);
	for(int i=1;i<=2*n;i++) scanf("%d",&a[i]);
	sort(a+1,a+2*n+1,cmp);
	int Ans=0;
	for(int i=1;i<=n;i++) Ans=(Ans-a[i]+mod)%mod;
	for(int i=1;i<=n;i++) Ans=(Ans+a[i+n])%mod;
	Ans=(ll)Ans*fl[2*n]%mod*nf[n]%mod*nf[n]%mod;
	printf("%d\n",Ans);
	return 0;
}