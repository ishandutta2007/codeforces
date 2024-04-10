#include <bits/stdc++.h>

using namespace std;

int N;
int A[300];
int B[300];
vector<int> dfactors[300];
int has[300];
int dp[1<<10];

int solve(int mask)
{
    if(mask==0)
        return 0;
    int& ret=dp[mask];
    if(ret!=-1)
        return ret;
    ret=0x3f3f3f3f;
    for(int i=0; i<N; i++)
    {
        int newmask=mask&has[i];
        if(mask!=newmask)
            ret=min(ret, solve(newmask)+B[i]);
    }
    return ret;
}

int main()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++)
    {
        scanf("%d", A+i);
        int x=A[i];
        for(int j=2; j*j<=x; j++)
        {
            int cnt=0;
            while(x%j==0)
                cnt++, x/=j;
            if(cnt>0)
                dfactors[i].push_back(j);
        }
        if(x>1)
            dfactors[i].push_back(x);
    }
    for(int i=0; i<N; i++)
        scanf("%d", B+i);
    int ans=0x3f3f3f3f;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            has[j]=0;
            for(size_t k=0; k<dfactors[i].size(); k++)
            {
                bool good=false;
                for(size_t l=0; l<dfactors[j].size(); l++)
                    if(dfactors[i][k]==dfactors[j][l])
                    {
                        good=true;
                        break;
                    }
                if(good)
                    has[j]|=1<<k;
            }
        }
        memset(dp, -1, sizeof dp);
        ans=min(ans, B[i]+solve((1<<dfactors[i].size())-1));
    }
    if(ans==0x3f3f3f3f)
        printf("-1\n");
    else
        printf("%d\n", ans);
    return 0;
}