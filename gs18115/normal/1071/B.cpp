#include<iostream>
#include<queue>
using namespace std;
const int INF=1e9;
char S[2345][2345];
int dp[2345][2345];
bool chk[2345][2345];
int N,K;
int i,j;
int maxi;
char mini[4567];
int x,y;
queue<int>Q[4567];
queue<int>Q2;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N>>K;
    for(i=1;i<=N;i++)
        cin>>S[i]+1;
    if(S[1][1]=='a')
        dp[1][1]=1;
    else
        dp[1][1]=0;
    for(i=0;i<N+2;i++)
        S[0][i]=S[i][0]=S[N+1][i]=S[i][N+1]='z'+1;
    for(i=1;i<=N;i++)
    {
        for(j=1;j<=N;j++)
        {
            if(i+j>=K+dp[i][j]+2)
                continue;
            maxi=max(maxi,dp[i][j]);
            if(S[i][j+1]=='a')
                dp[i][j+1]=max(dp[i][j]+1,dp[i][j+1]);
            else if(i+j<K+dp[i][j]+1)
                dp[i][j+1]=max(dp[i][j],dp[i][j+1]);
            if(S[i+1][j]=='a')
                dp[i+1][j]=max(dp[i][j]+1,dp[i+1][j]);
            else if(i+j<K+dp[i][j]+1)
                dp[i+1][j]=max(dp[i][j],dp[i+1][j]);
        }
    }
    if(K+maxi>0)
    {
        if(K+maxi>=2*N)
            K=2*N-1-maxi;
        for(i=0;i<K+maxi;i++)
            cout<<'a';
        for(i=max(1,K+maxi+1-N);i<=min(K+maxi,N);i++)
            if(dp[i][K+maxi+1-i]==maxi)
                Q[K+maxi+1].push(i);
        for(i=K+maxi+1;i<N*2;i++)
        {
            mini[i+1]='z'+1;
            while(!Q[i].empty())
            {
                x=Q[i].front();
                Q[i].pop();
                y=i-x;
                Q2.push(x);
                if(mini[i+1]>S[x+1][y])
                    mini[i+1]=S[x+1][y];
                if(mini[i+1]>S[x][y+1])
                    mini[i+1]=S[x][y+1];
            }
            cout<<mini[i+1];
            while(!Q2.empty())
            {
                x=Q2.front();
                Q2.pop();
                y=i-x;
                if(i<N*2)
                {
                    if(mini[i+1]==S[x+1][y]&&!chk[x+1][y])
                    {
                        chk[x+1][y]=true;
                        Q[i+1].push(x+1);
                    }
                    if(mini[i+1]==S[x][y+1]&&!chk[x][y+1])
                    {
                        chk[x][y+1]=true;
                        Q[i+1].push(x);
                    }
                }
            }
        }
    }
    else
    {
        cout<<S[1][1];
        Q[2].push(1);
        for(i=2;i<N*2;i++)
        {
            mini[i+1]='z'+1;
            while(!Q[i].empty())
            {
                x=Q[i].front();
                Q[i].pop();
                y=i-x;
                Q2.push(x);
                if(mini[i+1]>S[x+1][y])
                    mini[i+1]=S[x+1][y];
                if(mini[i+1]>S[x][y+1])
                    mini[i+1]=S[x][y+1];
            }
            cout<<mini[i+1];
            while(!Q2.empty())
            {
                x=Q2.front();
                Q2.pop();
                y=i-x;
                if(i<N*2)
                {
                    if(mini[i+1]==S[x+1][y]&&!chk[x+1][y])
                    {
                        chk[x+1][y]=true;
                        Q[i+1].push(x+1);
                    }
                    if(mini[i+1]==S[x][y+1]&&!chk[x][y+1])
                    {
                        chk[x][y+1]=true;
                        Q[i+1].push(x);
                    }
                }
            }
        }
    }
    return 0;
}