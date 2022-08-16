#include<bits/stdc++.h>

int main()
{
    std::string s;
    std::cin>>s;

    int dp[3]={};
    for(auto c:s)
    {
        if(c=='a')
        {
            dp[2] = std::max(dp[2]+1, dp[1]+1);
            dp[0] = dp[0]+1;
        }
        else
        {
            dp[1] = std::max(dp[1]+1,dp[0]+1);
        }
    }
    std::cout<<std::max({dp[0],dp[1],dp[2]});

    return 0;
}