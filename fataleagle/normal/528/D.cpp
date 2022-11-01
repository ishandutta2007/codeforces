#include <bits/stdc++.h>

using namespace std;

int N, M, K;
char S[200001];
char T[200001];
int A[200001];
int B[200001];
int sum[4][200001];
bitset<200000> ans;
bitset<200000> valid[4];

void convert(int len, char X[], int Y[])
{
    for(int i=0; i<len; i++)
    {
        switch(X[i])
        {
        case 'A':
            Y[i]=0;
            break;
        case 'C':
            Y[i]=1;
            break;
        case 'G':
            Y[i]=2;
            break;
        case 'T':
            Y[i]=3;
            break;
        }
    }
}

int main()
{
    scanf("%d%d%d", &N, &M, &K);
    scanf("%s", S);
    scanf("%s", T);
    convert(N, S, A);
    convert(M, T, B);
    for(int j=0; j<4; j++)
        for(int i=0; i<N; i++)
            sum[j][i]=(i?sum[j][i-1]:0)+(A[i]==j);
    for(int j=0; j<4; j++)
        for(int i=0; i<N; i++)
        {
            int l=max(0, i-K);
            int r=min(N-1, i+K);
            if(sum[j][r]-(l?sum[j][l-1]:0))
                valid[j][i]=1;
            else
                valid[j][i]=0;
        }
    for(int i=0; i<N-M+1; i++)
        ans[i]=1;
    for(int i=0; i<M; i++)
    {
        ans&=(valid[B[i]]>>i);
#if 0
        for(int j=0; j<N; j++)
            printf("%d", ans[j]?1:0);
        printf("\n");
#endif
    }
    printf("%d\n", ans.count());
    return 0;
}