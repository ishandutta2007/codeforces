#include <bits/stdc++.h>

using namespace std;

int N;
int A[101];
const int primes[]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59};
const int nprimes=sizeof(primes)/sizeof(int);
int dp[102][1<<nprimes];
int V[60][1<<nprimes];
int path[101][1<<nprimes];
vector<int> good[1<<nprimes];

inline int valid(int n, int mask)
{
    int ret=mask;
    for(int i=0; i<nprimes; i++)
        if(n%primes[i]==0)
        {
            if((mask>>i)&1)
                return -1;
            ret|=1<<i;
        }
    return ret;
}

int main()
{
    for(int i=1; i<60; i++)
        for(int j=0; j<(1<<nprimes); j++)
        {
            V[i][j]=valid(i, j);
            if(V[i][j]!=-1)
                good[j].push_back(i);
        }
    scanf("%d", &N);
    for(int i=1; i<=N; i++)
        scanf("%d", A+i);
    for(int pos=N; pos>=1; pos--)
        for(int mask=0; mask<(1<<nprimes); mask++)
        {
            dp[pos][mask]=0x3f3f3f3f;
            for(auto i: good[mask])
            {
                int val=abs(i-A[pos])+dp[pos+1][V[i][mask]];
                if(val<dp[pos][mask])
                {
                    dp[pos][mask]=val;
                    path[pos][mask]=i;
                }
            }
        }
    int mask=0;
    for(int i=1; i<=N; i++)
        printf("%d ", path[i][mask]), mask=V[path[i][mask]][mask];
    printf("\n");
    return 0;
}