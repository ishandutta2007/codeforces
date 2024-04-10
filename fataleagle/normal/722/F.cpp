#include <bits/stdc++.h>

using namespace std;

struct info
{
    int i, c, m;
};

int N, M;
vector<info> A[100001];
int cnt[41];
int which[41];
int g[41][41];

bool check()
{
    for(int i=1; i<=40; i++) if(cnt[i])
        for(int j=i+1; j<=40; j++) if(cnt[j])
            if(which[i]%g[i][j]!=which[j]%g[i][j])
                return false;
    return true;
}

int subsolve(info *V, int n)
{
    for(int i=1; i<=40; i++)
        cnt[i]=0;
    int ret=0;
    for(int i=0, j=0; j<n; j++)
    {
        while(cnt[V[j].m]>0 && which[V[j].m]!=V[j].c)
        {
            cnt[V[i].m]--;
            i++;
        }
        cnt[V[j].m]++;
        which[V[j].m]=V[j].c;
        while(!check())
        {
            cnt[V[i].m]--;
            i++;
        }
        ret=max(ret, j-i+1);
    }
    return ret;
}

int solve(vector<info>& V)
{
    int ret=0;
    for(int i=0, j; i<(int)V.size(); i=j)
    {
        for(j=i; j<(int)V.size() && j-i==V[j].i-V[i].i; j++);
        ret=max(ret, subsolve((info*)(V.data()+i), j-i));
    }
    return ret;
}

int main()
{
    for(int i=1; i<=40; i++)
        for(int j=1; j<=40; j++)
            g[i][j]=__gcd(i, j);
    scanf("%d%d", &N, &M);
    for(int i=0; i<N; i++)
    {
        int K;
        scanf("%d", &K);
        for(int j=0; j<K; j++)
        {
            int a;
            scanf("%d", &a);
            A[a].push_back((info){i, j, K});
        }
    }
    for(int i=1; i<=M; i++)
        printf("%d\n", solve(A[i]));
    return 0;
}