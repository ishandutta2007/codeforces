#include<cstdio>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define mo 1000000007
#define mx 4001
using namespace std;
long long a[mx][mx],b[mx],s[mx][mx],ans;int n;
int main(){
    scanf("%d",&n);a[0][0]=1;s[0][0]=1;
    rep(i,1,n)rep(j,0,i)a[i][j]=(a[i-1][j-1]+a[i-1][j]*j)%mo;
    rep(i,1,n)rep(j,0,i)s[i][j]=(s[i-1][j-1]+s[i-1][j])%mo;
    rep(i,0,n)rep(j,0,i)b[i]=(a[i][j]+b[i])%mo;
    rep(i,1,n)ans=(ans+b[n-i]*s[n][i])%mo;
    printf("%I64d\n",ans);
}