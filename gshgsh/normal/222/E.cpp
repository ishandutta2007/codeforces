#include<iostream>
#include<cstring>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define P 1000000007
#define MAXM 52
int M,K;ll N;struct mat{int a[MAXM][MAXM];mat(int x=0){memset(a,0,sizeof(a));if(x)For(i,0,M-1)a[i][i]=1;}}a;
mat operator*(mat x,mat y){mat z(0);For(i,0,M-1)For(j,0,M-1)For(k,0,M-1)z.a[i][j]=(z.a[i][j]+1ll*x.a[i][k]*y.a[k][j])%P;return z;}
mat pow(mat a,ll b){mat ans(1);while(b)b&1?ans=ans*a,0:0,a=a*a,b>>=1;return ans;}
int turn(char x){if(x>='a'&&x<='z')return x-'a';return x-'A'+26;}
int main(){cin>>N>>M>>K;For(i,0,M-1)For(j,0,M-1)a.a[i][j]=1;For(i,1,K){char x,y;cin>>x>>y;a.a[turn(y)][turn(x)]=0;}a=pow(a,N-1);int ans=0;For(i,0,M-1)For(j,0,M-1)ans=(ans+a.a[i][j])%P;cout<<ans<<endl;return 0;}