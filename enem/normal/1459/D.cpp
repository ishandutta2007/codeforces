#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    static int dp[105][10005], tp[105][10005];

    int n;
    cin>>n;

    for(int j=0; j<105; j++)
    {
        for(int k=0; k<10005; k++)
        {
            dp[j][k]=(-(1<<30));
        }
    }
    dp[0][0]=0;

    int sm=0;

    for(int i=0; i<n; i++)
    {
        int a,b;
        cin>>a>>b;

        sm+=b;

        // tp[j][k] = dp[i-1][j][k] and from that we build dp[i][j][k] which is dp[j][k] in this code
        for(int j=0; j<105; j++)
        {
            for(int k=0; k<10005; k++)
            {
                tp[j][k] = dp[j][k];
            }
        }

        for(int j=1; j<105; j++)
        {
            for(int k=a; k<10005; k++)
            {
                dp[j][k] = max(dp[j][k], tp[j-1][k-a] + b);
            }
        }
    }

    for(int j=1; j<=n ; j++)
    {
        float ans=0;

        for(int k=0; k<10005; k++)
        {
            ans=max(ans, min((dp[j][k]+sm)/((float)2), (float)k) );
        }

        cout<<ans<<' ';
    }


    return 0;
}