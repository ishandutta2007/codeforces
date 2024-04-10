#include<algorithm>
#include<iostream>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define P 998244353
#define MAXN 1001
#define MAXM 100001
int N,M,a[MAXN],f[MAXN][MAXN],ans[MAXM],res;
int main()
{
	cin>>N>>M;For(i,1,N)cin>>a[i];sort(a+1,a+N+1);a[0]=-P;
	For(k,0,(a[N]-a[1])/(M-1)){For(i,1,N)For(j,1,M)f[i][j]=0;f[0][0]=1;For(j,1,M){int sum=f[0][j-1],r=0;For(i,j,N){while(r+1<i&&a[i]-a[r+1]>=k)sum=(sum+f[++r][j-1])%P;f[i][j]=sum;}}For(i,M,N)ans[k]=(ans[k]+f[i][M])%P;}
	For(i,0,(a[N]-a[1])/(M-1))ans[i]-=ans[i+1],res=(res+1ll*i*ans[i])%P;cout<<res<<endl;return 0;
}