#include<bits/stdc++.h>
#define maxn 123456

using namespace std;
typedef long long ll;
const ll M=998244353;
int dp[505][505],f[505],n,k,o;
ll ans;
void add(int &x,int y){
    x+=y; if (x>=M) x-=M;
}
int main(){
    cin >> n >> k;
    dp[0][0]=1;
    for (int i=0;i<n;i++)
        for (int j=0;j<=i;j++)
            for (int k=1;k+i<=n;k++)
                add(dp[i+k][max(j,k)],dp[i][j]);
    for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) if (i*j<k) (ans+=1ll*dp[n][i]*dp[n][j])%=M;
    cout << ans*2%M << endl;
}