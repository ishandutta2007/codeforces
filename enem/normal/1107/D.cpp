#include <bits/stdc++.h>
using namespace std;
#define ll int
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define REPI(i,a,b) for(ll i=b-1;i>=a;i--)

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    static const ll N=5405;
    static char a[N][N];
    static int dp[N][N];
    
    int n;
    string s;
    string mp[255];
    mp['0']="0000";
    mp['1']="0001";
    mp['2']="0010";
    mp['3']="0011";
    mp['4']="0100";
    mp['5']="0101";
    mp['6']="0110";
    mp['7']="0111";
    mp['8']="1000";
    mp['9']="1001";
    mp['A']="1010";
    mp['B']="1011";
    mp['C']="1100";
    mp['D']="1101";
    mp['E']="1110";
    mp['F']="1111";

    cin>>n;
    REP(i,0,n)
    {
        cin>>s;
        REP(j,0,(n>>2))
        {
            a[i][(j<<2)|0]=mp[s[j]][0];
            a[i][(j<<2)|1]=mp[s[j]][1];
            a[i][(j<<2)|2]=mp[s[j]][2];
            a[i][(j<<2)|3]=mp[s[j]][3];
        }
    }
    REPI(i,0,n)
    {
        REPI(j,0,n)
        {
            if(i==n-1||j==n-1)
            {
                dp[i][j]=1;
            }
            else
            {
                if(a[i][j]==a[i+1][j]&&a[i][j]==a[i][j+1])
                {
                    if(a[i][j]==a[i+min(dp[i][j+1],dp[i+1][j])][j+min(dp[i][j+1],dp[i+1][j])])
                        dp[i][j]=min(dp[i][j+1],dp[i+1][j])+1;
                    else
                        dp[i][j]=min(dp[i][j+1],dp[i+1][j]);
                }
                else
                    dp[i][j]=1;
            }
        }
    }
    // REP(i,0,n)
    // {
    //     REP(j,0,n)
    //     {
    //         cout<<a[i][j];
    //     }
    //     cout<<'\n';
    // }
    // REP(i,0,n)
    // {
    //     REP(j,0,n)
    //     {
    //         cout<<dp[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }
    REPI(k,1,n+1)
    {
        if(n%k!=0) continue;
        bool bad=false;
        for(int i=0;i<n;i+=k)
        {
            for(int j=0;j<n;j+=k)
            {
                if(dp[i][j]<k) bad=true;
            }
        }
        if(!bad)
        {
            cout<<k;
            break;
        }
    }

    return 0;
}