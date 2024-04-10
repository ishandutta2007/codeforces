#include<iostream>
#include<vector>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define P 998244353
#define MAXN 300001
int N,M,f[MAXN],cnt,pow[MAXN],ans;vector<int>a[MAXN];
int main()
{
	cin>>N>>M;For(i,1,N){a[i].resize(M+1);For(j,1,M){char c;cin>>c;cnt+=a[i][j]=c=='o';}}
	pow[0]=1;For(i,1,N*M)pow[i]=pow[i-1]*2%P;For(i,2,max(N,M))f[i]=(0ll+f[i-1]+f[i-2]*2+pow[i-2])%P;
	For(i,1,N){int tot=0;For(j,1,M)if(a[i][j])tot++;else ans=(ans+1ll*f[tot]*pow[cnt-tot])%P,tot=0;ans=(ans+1ll*f[tot]*pow[cnt-tot])%P;}
	For(j,1,M){int tot=0;For(i,1,N)if(a[i][j])tot++;else ans=(ans+1ll*f[tot]*pow[cnt-tot])%P,tot=0;ans=(ans+1ll*f[tot]*pow[cnt-tot])%P;}cout<<ans<<endl;return 0;
}