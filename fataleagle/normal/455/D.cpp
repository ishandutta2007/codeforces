#include <bits/stdc++.h>

using namespace std;

const int SZ=1230;
int N, Q, lastans;

struct block
{
    int L, R;
    int freq[100001];
    list<int> data;
    int update(int l, int r, int x)
    {
        int p=max(l, L), q=min(r, R);
        int ret=0;
        if(L<=l && r<=R)
        {
            auto it=data.begin();
            advance(it, r-L);
            int v=*it;
            data.erase(it);
            it=data.begin();
            advance(it, l-L);
            data.insert(it, v);
        }
        else if(p==L && q==R)
        {
            freq[x]++;
            data.push_front(x);
            ret=data.back();
            data.pop_back();
            freq[ret]--;
        }
        else if(q==R)
        {
            freq[x]++;
            auto it=data.begin();
            advance(it, l-L);
            data.insert(it, x);
            ret=data.back();
            data.pop_back();
            freq[ret]--;
        }
        else if(p==L)
        {
            auto it=data.begin();
            advance(it, r-L);
            freq[*it]--;
            data.erase(it);
            freq[x]++;
            data.push_front(x);
        }
        return ret;
    }
    int query(int l, int r, int x)
    {
        int p=max(l, L), q=min(r, R);
        if(p==L && q==R)
            return freq[x];
        int ret=0;
        auto it=data.begin();
        advance(it, p-L);
        for(int i=p; i<=q; i++, ++it)
            ret+=(*it)==x;
        return ret;
    }
} blocks[100000/SZ+5];

int main()
{
    scanf("%d", &N);
    int a, b, c, d;
    int cur=0, last=-1;
    for(int i=1; i<=N; i++)
    {
        cur=i/SZ;
        if(cur!=last)
        {
            if(last!=-1)
                blocks[last].R=i-1;
            blocks[cur].L=i;
            last=cur;
        }
        scanf("%d", &a);
        blocks[cur].data.push_back(a);
        blocks[cur].freq[a]++;
    }
    blocks[cur].R=N;
    scanf("%d", &Q);
    lastans=0;
    for(int i=0; i<Q; i++)
    {
        scanf("%d%d%d", &a, &b, &c);
        b=(b+lastans-1)%N+1;
        c=(c+lastans-1)%N+1;
        if(b>c)
            swap(b, c);
        int p=b/SZ, q=c/SZ;
        if(a==1)
        {
            if(b==c)
                continue;
            auto it=blocks[q].data.begin();
            advance(it, c-blocks[q].L);
            int last=*it;
            for(int i=p; i<=q; i++)
                last=blocks[i].update(b, c, last);
        }
        else
        {
            scanf("%d", &d);
            d=(d+lastans-1)%N+1;
            int ans=0;
            for(int i=p; i<=q; i++)
                ans+=blocks[i].query(b, c, d);
            printf("%d\n", ans);
            lastans=ans;
        }
    }
    return 0;
}