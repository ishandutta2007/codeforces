#include <bits/stdc++.h>

using namespace std;

int N;
int A[100100];

struct node
{
    int ans[60];
} seg[262144];

node combine(node a, node b)
{
    node c;
    for(int i=0; i<60; i++)
    {
        c.ans[i]=a.ans[i];
        //if(a.ans[i]%A[mid]==0)
            //c.ans[i]++;
        c.ans[i]+=b.ans[(i+c.ans[i])%60];
    }
    return c;
}

void init(int idx, int begin, int end)
{
    if(begin==end)
    {
        for(int i=0; i<60; i++)
            seg[idx].ans[i]=(i%A[begin]==0)?2:1;
    }
    else
    {
        int mid=(begin+end)/2;
        init(idx*2, begin, mid);
        init(idx*2+1, mid+1, end);
        seg[idx]=combine(seg[idx*2], seg[idx*2+1]);
    }
}

void update(int idx, int begin, int end, int x, int v)
{
    if(x<begin || end<x)
        return;
    if(begin==end)
    {
        A[begin]=v;
        for(int i=0; i<60; i++)
            seg[idx].ans[i]=(i%A[begin]==0)?2:1;
    }
    else
    {
        int mid=(begin+end)/2;
        update(idx*2, begin, mid, x, v);
        update(idx*2+1, mid+1, end, x, v);
        seg[idx]=combine(seg[idx*2], seg[idx*2+1]);
    }
}

node query(int idx, int begin, int end, int i, int j)
{
    if(j<begin || end<i)
    {
        node dummy;
        dummy.ans[0]=-1;
        return dummy;
    }
    if(i<=begin && end<=j)
        return seg[idx];
    int mid=(begin+end)/2;
    node a=query(idx*2, begin, mid, i, j);
    node b=query(idx*2+1, mid+1, end, i, j);
    if(a.ans[0]==-1)
        return b;
    if(b.ans[0]==-1)
        return a;
    return combine(a, b);
}

int main()
{
    scanf("%d", &N);
    for(int i=1; i<=N; i++)
        scanf("%d", A+i);
    int Q;
    scanf("%d", &Q);
    int a, b;
    char c;
    init(1, 1, N);
    for(int i=0; i<Q; i++)
    {
        scanf(" %c%d%d", &c, &a, &b);
        if(c=='C')
            update(1, 1, N, a, b);
        else
            printf("%d\n", query(1, 1, N, a, b-1).ans[0]);
    }
    return 0;
}