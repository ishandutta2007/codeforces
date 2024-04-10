#include<bits/stdc++.h>
#define N 505
#define M 1000000007

using namespace std;
typedef long long ll;
ll dp[N][N],s[N][N],n,a[N][N],ans,t;

int main()
{
    scanf("%d",&n);
    for (int i=0;i<n;i++) for (int j=0;j<n;j++) scanf("%d",&a[i][j]);
    for (int i=0;i<n;i++) s[i][0]=1;
    for (int i=1;i<n;i++)
        for (int j=0;j+i<n;j++)
        {
            for (int k=0;k<=i;k++) (s[j][i]+=s[j][k]*dp[j+k][i-k])%=M;
            for (int k=0;k<i;k++) (dp[j][i]+=s[j][k]*s[j+k+1][i-k-1]*a[j][i+j])%=M;
            (s[j][i]+=dp[j][i])%=M;
        }
    cout << s[0][n-1] << endl;
}