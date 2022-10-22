#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod=1e9+7,N=410;
int f[N][N];

int main()
{

    int n;
    scanf("%d",&n);

    memset(f,0,sizeof(f));
    f[1][1]=f[1][0]=1;

    for(int i=2;i<=n;i++)
        for(int j=0;j<=n;j++)
            for(int k=0;k<=n;k++){
                if(j+k+1<=n) f[i][j+k+1]=(f[i][j+k+1]+(ll)f[i-1][j]*f[i-1][k])%mod;
                if(j+k<=n){
                    f[i][j+k]=(f[i][j+k]+(ll)f[i-1][j]*f[i-1][k]%mod*(2*(j+k)+1))%mod;
                }
                if(j+k-1<=n){
                    f[i][j+k-1]=(f[i][j+k-1]+(ll)f[i-1][j]*f[i-1][k]%mod*(j+k)%mod*(j+k-1))%mod;
                }
            }

    printf("%d\n",f[n][1]);

    return 0;
}