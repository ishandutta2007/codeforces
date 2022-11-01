#include <bits/stdc++.h>

using namespace std;

int N, Q;
int A[100001];
int X[100001];
int seg[262144];

struct persistent_segtree
{
    enum {L, R};
    struct node
    {
        int sz;
        node *link[2];
    } pool[2*21*100000], *nextpool=pool, *tree[100001];
    void construct()
    {
        tree[0]=init(1, N);
        for(int i=1; i<=N; i++)
            tree[i]=update(tree[i-1], 1, N, lower_bound(X+1, X+1+N, A[i])-X, 1);
    }
    node* alloc(node *orig)
    {
        *nextpool=*orig;
        return nextpool++;
    }
    node* init(int begin, int end)
    {
        node *root=nextpool++;
        if(begin==end)
            return root;
        int mid=(begin+end)/2;
        root->link[L]=init(begin, mid);
        root->link[R]=init(mid+1, end);
        return root;
    }
    node* update(node *root, int begin, int end, int x, int v)
    {
        if(x<begin || end<x)
            return root;
        root=alloc(root);
        if(begin==end)
            root->sz+=v;
        else
        {
            int mid=(begin+end)/2;
            root->link[L]=update(root->link[L], begin, mid, x, v);
            root->link[R]=update(root->link[R], mid+1, end, x, v);
            root->sz=root->link[L]->sz+root->link[R]->sz;
        }
        return root;
    }
    int query(node *rootL, node *rootR, int begin, int end, int x)
    {
        if(x<begin || end<x)
            return 0;
        if(begin==end)
            return rootR->sz-rootL->sz;
        int mid=(begin+end)/2;
        return query(rootL->link[L], rootR->link[L], begin, mid, x)+
               query(rootL->link[R], rootR->link[R], mid+1, end, x);
    }
    int query(int i, int j, int x)
    {
        int nx=lower_bound(X+1, X+1+N, x)-X;
        if(X[nx]!=x)
            return 0;
        return query(tree[i-1], tree[j], 1, N, nx);
    }
} psegtree;

int gcd(int a, int b)
{
    if(!b)
        return a;
    return gcd(b, a%b);
}

void init(int idx, int begin, int end)
{
    if(begin==end)
        seg[idx]=A[begin];
    else
    {
        int mid=(begin+end)/2;
        init(idx*2, begin, mid);
        init(idx*2+1, mid+1, end);
        seg[idx]=gcd(seg[idx*2], seg[idx*2+1]);
    }
}

int query(int idx, int begin, int end, int i, int j)
{
    if(j<begin || end<i)
        return 0;
    if(i<=begin && end<=j)
        return seg[idx];
    int mid=(begin+end)/2;
    return gcd(query(idx*2, begin, mid, i, j),
               query(idx*2+1, mid+1, end, i, j));
}

int main()
{
    scanf("%d", &N);
    for(int i=1; i<=N; i++)
        scanf("%d", A+i), X[i]=A[i];
    init(1, 1, N);
    sort(X+1, X+1+N);
    psegtree.construct();
    scanf("%d", &Q);
    int a, b;
    for(int i=0; i<Q; i++)
    {
        scanf("%d%d", &a, &b);
        int g=query(1, 1, N, a, b);
        printf("%d\n", b-a+1-psegtree.query(a, b, g));
    }
    return 0;
}