#include<iostream>
using namespace std;
const int INF=1e9;
int N,i,j,val,C;
int dp[8];
char S[5];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N;
    dp[0]=0;
    for(i=1;i<8;i++)
        dp[i]=INF;
    for(i=0;i<N;i++)
    {
        cin>>C>>S;
        val=0;
        for(j=0;S[j];j++)
            val|=1<<S[j]-65;
        for(j=0;j<8;j++)
            dp[val|j]=min(dp[val|j],dp[j]+C);
    }
    if(dp[7]==INF)
        cout<<-1<<endl;
    else
        cout<<dp[7]<<endl;
    return 0;
}