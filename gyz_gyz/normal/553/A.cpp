#include<cstdio>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define mo 1000000007
using namespace std;
int n,s,a[1001];long long ans,f[1001][1001];
int main(){
    scanf("%d",&n);s=1;ans=1;
    rep(i,1,n)scanf("%d",&a[i]);
    rep(i,1,1000)f[i][1]=1,f[1][i]=1;
    rep(i,2,1000)rep(j,2,1000)
        f[i][j]=(f[i-1][j]+f[i][j-1])%mo;
    rep(i,1,n){
        ans=ans*f[s][a[i]]%mo;s+=a[i];
    }
    printf("%I64d\n",ans);
}