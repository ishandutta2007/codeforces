#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
typedef pair<LL,LL>PL;
const int INF=1e9;
int dp[1000010][3][3];
int A[1000010];
int N,M,i,j,k,l;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N>>M;
    for(i=0;i<N;i++)
    {
        cin>>j;
        A[j]++;
    }
    for(i=0;i<=M;i++)
        for(j=0;j<3;j++)
            for(k=0;k<3;k++)
                dp[i][j][k]=-INF;
    dp[0][0][0]=0;
    for(i=1;i<=M;i++)
        for(j=0;j<3;j++)
            for(k=0;k<3;k++)
                for(l=0;l<3;l++)
                    dp[i][j][k]=max(dp[i][j][k],l+j+k>A[i]||j+k>A[i+1]||k>A[i+2]?-INF:dp[i-1][l][j]+(A[i]-l-j-k)/3+k);
    cout<<dp[M][0][0]<<endl;
    return 0;
}