#include <bits/stdc++.h>

using namespace std;

const int SZ=350;
int N;
int T[150000];
int V[150000];
int pop[150000];
int push[150000/SZ+5][SZ+5];
int ptr[150000];
int A[150000];
int B[150000];
int M;

void rebuild(int b)
{
    ptr[b]=0;
    pop[b]=0;
    int p=0;
    for(int i=b*SZ; i<(b+1)*SZ; i++)
    {
        if(T[i]==0)
        {
            if(ptr[b]>0)
                ptr[b]--;
            p++;
            pop[b]=max(pop[b], p);
        }
        else if(T[i]==1)
        {
            push[b][ptr[b]++]=V[i];
            p--;
        }
    }
}

int main()
{
    memset(T, -1, sizeof T);
    scanf("%d", &N);
    for(int i=0; i<N; i++)
    {
        int idx, t;
        scanf("%d%d", &idx, &t);
        idx--;
        T[idx]=t;
        if(t==1)
            scanf("%d", V+idx);
        int blk=idx/SZ;
        rebuild(blk);
        M=0;
        for(int j=0, k=(N-1)/SZ; j<=k; j++)
        {
            int p=pop[j];
            while(M>0 && B[M-1]<=p)
                p-=B[--M];
            if(M>0)
                B[M-1]-=p;
            if(ptr[j]>0)
            {
                A[M]=j;
                B[M++]=ptr[j];
            }
        }
        if(M==0)
            printf("-1\n");
        else
            printf("%d\n", push[A[M-1]][B[M-1]-1]);
    }
    return 0;
}