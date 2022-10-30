#include <bits/stdc++.h>

using namespace std;

const int SZ=400;
int N, Q;
long long A[500000];

struct bucket
{
    int l, r;
    long long lazy;
    vector<pair<long long, int>> v;
    bucket()
    {
        l=0x3f3f3f3f;
        r=-0x3f3f3f3f;
    }
    void down()
    {
        v.clear();
        for(int i=l; i<=r; i++)
        {
            A[i]+=lazy;
            v.push_back(make_pair(A[i], i));
        }
        sort(v.begin(), v.end());
        lazy=0;
    }
    int find_first(long long x)
    {
        x-=lazy;
        auto it=lower_bound(v.begin(), v.end(), make_pair(x, 0));
        if(it==v.end() || it->first!=x)
            return -1;
        return it->second;
    }
    int find_last(long long x)
    {
        x-=lazy;
        auto it=lower_bound(v.begin(), v.end(), make_pair(x+1, 0));
        if(it==v.begin())
            return -1;
        --it;
        if(it->first!=x)
            return -1;
        return it->second;
    }
    void update(int p, int q, long long v)
    {
        if(p<=l && r<=q)
        {
            lazy+=v;
            return;
        }
        if(lazy)
            down();
        for(int i=max(p, l); i<=min(q, r); i++)
            A[i]+=v;
        down();
    }
} buckets[500000/SZ+5];

int main()
{
    scanf("%d%d", &N, &Q);
    for(int i=0; i<N; i++)
    {
        scanf("%lld", A+i);
        int idx=i/SZ;
        buckets[idx].l=min(buckets[idx].l, i);
        buckets[idx].r=max(buckets[idx].r, i);
    }
    for(int i=0; i<N; i++) if(i==0 || i/SZ!=(i-1)/SZ)
        buckets[i/SZ].down();
    int a, b, c, op;
    for(int i=0; i<Q; i++)
    {
        scanf("%d", &op);
        if(op==1)
        {
            scanf("%d%d%d", &a, &b, &c);
            a--, b--;
            for(int i=a/SZ; i<=b/SZ; i++)
                buckets[i].update(a, b, c);
        }
        else
        {
            scanf("%d", &a);
            int first=-1;
            for(int i=0; first==-1 && i<=(N-1)/SZ; i++)
                first=buckets[i].find_first(a);
            if(first==-1)
                printf("-1\n");
            else
            {
                int last=-1;
                for(int i=(N-1)/SZ; last==-1 && i>=0; i--)
                    last=buckets[i].find_last(a);
                printf("%d\n", last-first);
            }
        }
    }
    return 0;
}