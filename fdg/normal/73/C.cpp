#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <set>

#define ll long long

using namespace std;

int D[30][30]={0};

int dp[102][102][30]={0};

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,k,c;
    string s;
    cin >> s >> k >> n;
    char a,b;
    for(int i=0;i<=26;i++)
        for(int j=0;j<=26;j++)
            D[i][j]=0;
    for(int i=0;i<n;i++)
    {
        cin >> a >> b >> c;
        D[a-'a'][b-'a']=c;
    }
    for(int j=0;j<=s.size();j++)
        for(int i=0;i<=k;i++)
            for(int t=0;t<=26;t++)
                dp[j][i][t]=-1000000000;
    for(int i=0;i<26;i++)
    {
        if (s[0]==char('a'+i)) dp[1][k][i]=0;
        else if (k>0) dp[1][k-1][i]=0;
    }
    for(int l=1;l<s.size();l++)
    {
        for(int kk=0;kk<=k;kk++)
        {
            for(int i=0;i<26;i++)
            {
                if (dp[l][kk][i]==-1000000000) continue;
                for(int j=0;j<26;j++)
                {
                    if (s[l]==char('a'+j))
                    {
                        dp[l+1][kk][j]=max(dp[l+1][kk][j],dp[l][kk][i]+D[i][j]);
                    }
                    else
                    {
                        if (kk>0)
                        {
                            dp[l+1][kk-1][j]=max(dp[l+1][kk-1][j],dp[l][kk][i]+D[i][j]);
                        }
                    }
                }
            }
        }
    }
    int best=-1000000000;
    for(int i=0;i<26;i++)
        for(int kk=0;kk<=k;kk++)
            best=max(best,dp[s.size()][kk][i]);
    cout << best << endl;
    return 0;
}