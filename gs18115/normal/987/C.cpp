#include<iostream>
using namespace std;
struct ST
{
    int s,c;
}d[123456];
int i,j,n,flag,mi;
int pa[123456],chk[123456],dp[123456][3];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(i=0;i<n;i++)
        cin>>d[i].s;
    for(i=0;i<n;i++)
        cin>>d[i].c;
    for(i=0;i<n;i++)
    {
        dp[i][0]=d[i].c;
        dp[i][1]=1000000000;
        dp[i][2]=1000000000;
        for(j=0;j<i;j++)
        {
            if(dp[j][0]+d[i].c<dp[i][1]&&d[j].s<d[i].s)
                dp[i][1]=dp[j][0]+d[i].c;
            if(dp[j][1]+d[i].c<dp[i][2]&&d[j].s<d[i].s)
                dp[i][2]=dp[j][1]+d[i].c;
        }
    }
    mi=1000000000;
    for(i=0;i<n;i++)
        if(mi>dp[i][2])
            mi=dp[i][2];
    if(mi!=1000000000)
        cout<<mi;
    else
        cout<<-1;
    return 0;
}