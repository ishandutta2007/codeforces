#include <bits/stdc++.h>

long long __;
#define ABS(x) ((__=(x))<0?-(__):(__))

using namespace std;

const int SZ=300;
int N, M;
int A[100001];
long long X[100001];

struct block
{
    int l, r, first, last;
    long long add, sum;
    block()
    {
        first=last=-1;
        add=sum=0;
    }
    long long query(int b, int e)
    {
        if(b<=l && r<=e)
            return sum;
        long long ret=0;
        rebuild();
        int p=max(l, b);
        int q=min(r, e);
        for(int i=p; i<=q; i++)
            ret+=X[i];
        return ret;
    }
    void rebuild()
    {
        if(first==-1)
            return;
        for(int i=l; i<=r; i++)
            A[i]=last, X[i]+=add;
        add=0;
        first=last=-1;
    }
    void change(int b, int e, int val)
    {
        if(b<=l && r<=e)
        {
            if(first==-1)
            {
                first=last=val;
                for(int i=l; i<=r; i++)
                {
                    int v=ABS(val-A[i]);
                    sum+=v;
                    X[i]+=v;
                }
            }
            else
            {
                sum+=(long long)(r-l+1)*ABS(val-last);
                add+=ABS(val-last);
                last=val;
            }
            return;
        }
        rebuild();
        int p=max(l, b);
        int q=min(r, e);
        for(int i=p; i<=q; i++)
        {
            int v=ABS(val-A[i]);
            sum+=v;
            X[i]+=v;
            A[i]=val;
        }
    }
} blocks[100000/SZ+10];

int main()
{
    scanf("%d%d", &N, &M);
    int a, b, c, d;
    int last=-1, cur=-1;
    for(int i=1; i<=N; i++)
    {
        A[i]=i;
        cur=i/SZ;
        if(cur!=last)
        {
            if(last!=-1)
                blocks[last].r=i-1;
            last=cur;
            blocks[cur].l=i;
        }
    }
    if(cur!=-1)
        blocks[cur].r=N;
    for(int i=0; i<M; i++)
    {
        scanf("%d", &a);
        if(a==1)
        {
            scanf("%d%d%d", &b, &c, &d);
            int l=b/SZ;
            int r=c/SZ;
            for(int i=l+1; i<r; i++)
                blocks[i].change(b, c, d);
            blocks[l].change(b, c, d);
            if(l!=r)
                blocks[r].change(b, c, d);
        }
        else
        {
            scanf("%d%d", &b, &c);
            int l=b/SZ;
            int r=c/SZ;
            long long ans=0;
            for(int i=l+1; i<r; i++)
                ans+=blocks[i].query(b, c);
            ans+=blocks[l].query(b, c);
            if(l!=r)
                ans+=blocks[r].query(b, c);
            printf("%lld\n", ans);
        }
    }
    return 0;
}