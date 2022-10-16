#include<cstdio>
using namespace std;
int dp[510][510],v[510];
int minim(int a,int b){
    if(a<b)
        return a;
    return b;
}
int main(){
    //freopen("tema.in","r",stdin);
    //freopen("tema.out","w",stdout);
    int i,j,l,k,n;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&v[i]);
        dp[i][i]=1;
    }
    for(l=2;l<=n;l++)
        for(i=1;i+l-1<=n;i++){
            j=i+l-1;
            dp[i][j]=1+dp[i+1][j];
            if(v[i]==v[i+1])
                dp[i][j]=minim(dp[i][j],1+dp[i+2][j]);
            for(k=i+2;k<=j;k++)
                if(v[i]==v[k])
                    dp[i][j]=minim(dp[i][j],dp[i+1][k-1]+dp[k+1][j]);
        }
    printf("%d",dp[1][n]);
    return 0;
}