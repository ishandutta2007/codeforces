#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef
tree<
  int,
  int,
  less<int>,
  rb_tree_tag,
  tree_order_statistics_node_update>
map_t;

int N;
int A[300000];
pair<int, int> B[300000];
long long ans;
map_t trees[2000000];

struct info
{
    int mini, maxi, idx;
};

vector<info> L, R;
vector<int> used;

void update(int idx, int v)
{
    idx+=1000000;
    trees[idx].insert({v, 0});
    used.push_back(idx);
}

int query(int idx, int v)
{
    idx+=1000000;
    return trees[idx].order_of_key(v);
}

void clear()
{
    for(size_t i=0; i<used.size(); i++)
        trees[used[i]].clear();
    used.clear();
}

void solve(int l, int r)
{
    if(l==r)
        return;
    int m=(l+r)/2;
    solve(l, m);
    solve(m+1, r);
    L.clear();
    R.clear();
    pair<int, int> tmp={A[m], A[m]};
    int cnt=0;
    for(int i=m; i>=l; i--)
    {
        tmp.first=min(tmp.first, A[i]);
        tmp.second=max(tmp.second, A[i]);
        L.push_back({tmp.first, tmp.second, cnt});
        cnt++;
    }
    tmp={A[m+1], A[m+1]};
    cnt=0;
    for(int i=m+1; i<=r; i++)
    {
        tmp.first=min(tmp.first, A[i]);
        tmp.second=max(tmp.second, A[i]);
        R.push_back({tmp.first, tmp.second, cnt});
        cnt++;
    }
    size_t ptr;
    // L.min < R.min, L.max < R.max
    ptr=0;
    for(size_t i=0; i<R.size(); i++)
    {
        while(ptr<L.size() && L[ptr].maxi<R[i].maxi)
        {
            update(L[ptr].idx+L[ptr].mini+1, L[ptr].mini);
            ptr++;
        }
        ans+=query(R[i].maxi-R[i].idx, R[i].mini);
    }
    clear();
#if 0
    for(size_t i=0; i<L.size(); i++)
        for(size_t j=0; j<R.size(); j++)
            if(L[i].mini<R[j].mini && L[i].maxi<R[j].maxi)
            if(R[j].maxi-R[j].idx==L[i].idx+L[i].mini+1)
                ans++;
#endif
    // R.min < L.min, L.max < R.max
    // -L.min < -R.min, L.max < R.max
    ptr=0;
    for(size_t i=0; i<R.size(); i++)
    {
        while(ptr<L.size() && L[ptr].maxi<R[i].maxi)
        {
            update(L[ptr].idx+1, -L[ptr].mini);
            ptr++;
        }
        ans+=query(R[i].maxi-R[i].mini-R[i].idx, -R[i].mini);
    }
    clear();
#if 0
    for(size_t i=0; i<L.size(); i++)
        for(size_t j=0; j<R.size(); j++)
            if(R[j].mini<L[i].mini && L[i].maxi<R[j].maxi)
            if(R[j].maxi-R[j].mini-R[j].idx==L[i].idx+1)
                ans++;
#endif
    // L.min < R.min, R.max < L.max
    // -R.min < -L.min, R.max < L.max
    ptr=0;
    for(size_t i=0; i<L.size(); i++)
    {
        while(ptr<R.size() && R[ptr].maxi<L[i].maxi)
        {
            update(R[ptr].idx+1, -R[ptr].mini);
            ptr++;
        }
        ans+=query(L[i].maxi-L[i].mini-L[i].idx, -L[i].mini);
    }
    clear();
#if 0
    for(size_t i=0; i<L.size(); i++)
        for(size_t j=0; j<R.size(); j++)
            if(L[i].mini<R[j].mini && R[j].maxi<L[i].maxi)
            if(L[i].maxi-L[i].mini-L[i].idx==R[j].idx+1)
                ans++;
#endif
    // R.min < L.min, R.max < L.max
    ptr=0;
    for(size_t i=0; i<L.size(); i++)
    {
        while(ptr<R.size() && R[ptr].maxi<L[i].maxi)
        {
            update(-R[ptr].mini-R[ptr].idx, R[ptr].mini);
            ptr++;
        }
        ans+=query(L[i].idx-L[i].maxi+1, L[i].mini);
    }
    clear();
#if 0
    for(size_t i=0; i<L.size(); i++)
        for(size_t j=0; j<R.size(); j++)
            if(R[j].mini<L[i].mini && R[j].maxi<L[i].maxi)
            if(-R[j].mini-R[j].idx==L[i].idx-L[i].maxi+1)
                ans++;
#endif
}

int main()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++)
        scanf("%d%d", &B[i].first, &B[i].second);
    sort(B, B+N);
    for(int i=0; i<N; i++)
        A[i]=B[i].second-1;
    solve(0, N-1);
    printf("%lld\n", ans+N);
    return 0;
}