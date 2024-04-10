#include<cstdio>
#include<cstring>
using namespace std;

typedef long long ll;
const int N=3e5+100,mod=998244353;
int a[N],f[N],g[N];

int mi(int x,int t){
	int d=1;
	while(t){
		if(t%2) d=(ll)d*x%mod;
		x=(ll)x*x%mod;t/=2;
	}
	return d;
}
int ni(int x) {return mi(x,mod-2);}

int main()
{
	
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	
	int Sum=0;
	for(int i=1;i<=n;i++) Sum+=a[i];
	
	f[0]=n-1;
	for(int i=1;i<Sum;i++){
		int t2=(ll)(Sum-i)*ni(n-1)%mod;
		f[i]=(Sum+(ll)i*f[i-1])%mod*ni(t2)%mod;
	}
	
	g[Sum]=0;for(int i=Sum-1;i>=0;i--) g[i]=(g[i+1]+f[i])%mod;
	int Ans=0;
	for(int i=1;i<=n;i++) Ans=(Ans+g[a[i]])%mod;
	Ans=(Ans-(ll)(n-1)*g[0]%mod+mod)%mod;
	
	printf("%d\n",(ll)Ans*ni(n)%mod);
	
	return 0;
}