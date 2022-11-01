#include <bits/stdc++.h>

using namespace std;

int N, M;
long long K;
long long A[1000];
vector<long long> D;
vector<int> nxt;
vector<int> dist[1001];
vector<long long> sum[1001];
vector<int> out[1001];
vector<pair<int, int>> pre[1001];
vector<long long> F;
vector<long long> G;

int main()
{
    scanf("%d%lld", &N, &K);
    if(K==1)
    {
        for(int i=0; i<N; i++)
            scanf("%lld", A+i);
        printf("1\n%d\n", min_element(A, A+N)-A+1);
        return 0;
    }
    for(long long i=1; i*i<=K; i++) if(K%i==0)
    {
        D.push_back(i);
        if(i*i!=K)
            D.push_back(K/i);
    }
    sort(D.begin(), D.end());
    M=D.size();
    nxt.resize(M);
    for(int i=0; i<M; i++)
    {
        for(int j=i+1; j<M; j++) if(D[j]%D[i]==0)
        {
            nxt[i]=j;
            break;
        }
    }
    for(int i=0; i<=N; i++)
    {
        dist[i].resize(M, N+1);
        sum[i].resize(M);
        out[i].resize(M);
        pre[i].resize(M, {-1, -1});
    }
    F.resize(M);
    G.resize(M);
    dist[0][M-1]=0;
    for(int i=0; i<N; i++)
    {
        scanf("%lld", A+i);
        for(int j=M-1; j>=0; j--)
        {
            if(j<M-1)
                G[j]=__gcd(D[j], G[nxt[j]]);
            else
                G[j]=__gcd(D[j], A[i]);
            long long x=D[j]/G[j];
            F[j]=lower_bound(D.begin(), D.end(), x)-D.begin();
        }
        for(int j=0; j<M; j++)
        {
            dist[i+1][j]=dist[i][j];
            sum[i+1][j]=sum[i][j];
            out[i+1][j]=out[i][j];
            pre[i+1][j]=pre[i][j];
        }
        for(int j=0; j<M; j++)
        {
            int f=F[j];
            if(dist[i][j]+1<dist[i+1][f] || (dist[i][j]+1==dist[i+1][f] && sum[i][j]+A[i]<sum[i+1][f]))
            {
                dist[i+1][f]=dist[i][j]+1;
                sum[i+1][f]=sum[i][j]+A[i];
                out[i+1][f]=i+1;
                pre[i+1][f]={i, j};
            }
        }
    }
    if(pre[N][0].first==-1)
        printf("-1\n");
    else
    {
        printf("%d\n", dist[N][0]);
        int x=N, y=0;
        while(pre[x][y].first!=-1)
        {
            printf("%d ", out[x][y]);
            tie(x, y)=pre[x][y];
        }
        printf("\n");
    }
    return 0;
}