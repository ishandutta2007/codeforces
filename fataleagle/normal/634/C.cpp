#include <bits/stdc++.h>

using namespace std;

int N, K, A, B, Q;
int capA[200001];
int capB[200001];

struct fenwick_tree
{
    int bit[200001];
    void add(int x, int v)
    {
        for(; x<=N; x+=x&-x)
            bit[x]+=v;
    }
    int sum(int x)
    {
        int ret=0;
        for(; x>0; x-=x&-x)
            ret+=bit[x];
        return ret;
    }
    int sum(int l, int r)
    {
        return sum(r)-sum(l-1);
    }
} treeA, treeB;

int main()
{
    scanf("%d%d%d%d%d", &N, &K, &A, &B, &Q);
    int a, b, op;
    for(int i=0; i<Q; i++)
    {
        scanf("%d", &op);
        if(op==1)
        {
            scanf("%d%d", &a, &b);
            int addA=min(A-capA[a], b);
            int addB=min(B-capB[a], b);
            capA[a]+=addA;
            capB[a]+=addB;
            treeA.add(a, addA);
            treeB.add(a, addB);
        }
        else
        {
            scanf("%d", &a);
            int ans=treeB.sum(1, a-1);
            ans+=treeA.sum(a+K, N);
            printf("%d\n", ans);
        }
    }
    return 0;
}