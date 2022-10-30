#include <bits/stdc++.h>

using namespace std;

struct card
{
    int a, b, c, d, i;
    bool operator< (const card& other) const
    {
        return a<other.a;
    }
} A[100001], O[100001];

int N, NX;
int X[300001];
int path[100001];

set<pair<int, int>> seg[1<<19];

int query(int idx, int begin, int end, int l, int r, int x)
{
    if(r<begin || end<l)
        return -1;
    if(l<=begin && end<=r)
    {
        auto it=seg[idx].upper_bound({x, 0x3f3f3f3f});
        if(it==seg[idx].begin())
            return -1;
        --it;
        return it->second;
    }
    int mid=(begin+end)/2;
    return max(query(idx*2, begin, mid, l, r, x),
               query(idx*2+1, mid+1, end, l, r, x));
}

void ins(int idx, int begin, int end, int x, pair<int, int> v)
{
    if(x<begin || end<x)
        return;
    seg[idx].insert(v);
    if(begin!=end)
    {
        int mid=(begin+end)/2;
        ins(idx*2, begin, mid, x, v);
        ins(idx*2+1, mid+1, end, x, v);
    }
}

void rem(int idx, int begin, int end, int x, pair<int, int> v)
{
    if(x<begin || end<x)
        return;
    seg[idx].erase(v);
    if(begin!=end)
    {
        int mid=(begin+end)/2;
        rem(idx*2, begin, mid, x, v);
        rem(idx*2+1, mid+1, end, x, v);
    }
}

int get(int x)
{
    return lower_bound(X, X+NX, x)-X+1;
}

int main()
{
    scanf("%d", &N);
    int a, b, c, d;
    for(int i=1; i<=N; i++)
    {
        scanf("%d%d%d%d", &a, &b, &c, &d);
        O[i]=A[i]=(card){a, b, c, d, i};
        X[NX++]=a;
        X[NX++]=c;
    }
    X[NX++]=0;
    sort(A+1, A+1+N);
    sort(X+1, X+1+NX);
    for(int i=1; i<=N; i++)
        ins(1, 1, NX, get(A[i].a), {A[i].b, A[i].i});
    queue<pair<pair<int, int>, int>> Q;
    Q.push({{0, 0}, -1});
    bool sol=false;
    while(!Q.empty())
    {
        int x=Q.front().first.first;
        int y=Q.front().first.second;
        int p=Q.front().second;
        Q.pop();
        if(p==N)
        {
            sol=true;
            break;
        }
        x=get(x);
        while(1)
        {
            int idx=query(1, 1, NX, 1, x, y);
            if(idx==-1)
                break;
            path[idx]=p;
            rem(1, 1, NX, get(O[idx].a), {O[idx].b, O[idx].i});
            Q.push({{O[idx].c, O[idx].d}, O[idx].i});
        }
    }
    if(!sol)
        printf("-1\n");
    else
    {
        vector<int> ans;
        int x=N;
        while(x!=-1)
        {
            ans.push_back(x);
            x=path[x];
        }
        reverse(ans.begin(), ans.end());
        printf("%d\n", (int)ans.size());
        for(auto& it: ans)
            printf("%d ", it);
        printf("\n");
    }
    return 0;
}