#ifndef SUFFIXARRAY_H_INCLUDED
#define SUFFIXARRAY_H_INCLUDED

#include <algorithm>
#include <vector>

class suffix_array
{
public:
    std::vector<int> suftab[2];
    std::vector<int> order;
    std::vector<int> sufarr;
    std::vector<int> bucket_count, bucket_size;
    std::vector<int> lcp; // lcp(sa[i], sa[i+1]) == sa.lcp[i]
    template<class T>
    void build_sa(T S[], int N)
    {
        suftab[0].resize(N);
        suftab[1].resize(N);
        order.resize(N);
        sufarr.resize(N);
        bucket_count.resize(N+1);
        bucket_size.resize(N+1);
        for(int i=0; i<N; i++)
            order[i]=S[i];
        std::sort(order.begin(), order.end());
        for(int i=0; i<N; i++)
            suftab[0][i]=std::lower_bound(order.begin(), order.end(), S[i])-order.begin();
        int lg=0;
        while((1<<lg)<N)
            lg++;
        int row=0;
        for(int hlen=1; hlen<(1<<lg); hlen*=2, row^=1)
        {
            bucket_count.assign(N+1, 0);
            int pos=0;
            for(int i=0; i+hlen<N; i++)
                bucket_count[suftab[row][i+hlen]+1]++;
            for(int i=N-hlen; i<N; i++)
                order[pos++]=i;
            bucket_count[0]=pos;
            std::partial_sum(bucket_count.begin(), bucket_count.end(), bucket_size.begin());
            for(int i=0; i+hlen<N; i++)
                order[bucket_size[suftab[row][i+hlen]]++]=i;
            bucket_count[0]=0;
            for(int i=0; i<hlen; i++)
                bucket_count[suftab[row][i]+1]++;
            std::partial_sum(bucket_count.begin(), bucket_count.end(), bucket_size.begin());
            for(int i=0; i<N; i++)
                sufarr[bucket_size[suftab[row][order[i]]]++]=order[i];
            int prev_a=-1, prev_b=-1, prev_c=-1;
            for(int i=0; i<N; i++)
            {
                const int x=sufarr[i];
                const int now_a=suftab[row][x];
                const int now_b=(x+hlen<N?suftab[row][x+hlen]:-1);
                prev_c+=now_a!=prev_a || now_b!=prev_b;
                suftab[row^1][x]=prev_c;
                prev_a=now_a;
                prev_b=now_b;
            }
        }
        if(row==1)
            suftab[0].swap(suftab[1]);
    }
    template<class T>
    void build(T S[], int N)
    {
        build_sa(S, N);
        lcp.resize(sufarr.size());
        for(int i=0, len=0; i<N; i++)
        {
            if(get_rank(i)==N-1)
                len=0;
            else
            {
                int j=sufarr[get_rank(i)+1];
                int maxl=N-std::max(i, j);
                while(len<maxl && S[i+len]==S[j+len])
                    len++;
                lcp[get_rank(i)]=len;
                if(len>0)
                    len--;
            }
        }
    }
    inline int get_rank(const int& idx) const
    {
        return suftab[0][idx];
    }
    int operator[] (const int& idx) const
    {
        return sufarr[idx];
    }
};

#endif // SUFFIXARRAY_H_INCLUDED

#include <bits/stdc++.h>

using namespace std;

int N;
char S[500001];
int sum[500001];
int len[500001];
suffix_array sa;
int seg[1<<20];
vector<int> pos[1<<20];

void build(int idx, int begin, int end)
{
    if(begin==end)
    {
        seg[idx]=sum[begin];
    }
    else
    {
        int mid=(begin+end)/2;
        build(idx*2, begin, mid);
        build(idx*2+1, mid+1, end);
        seg[idx]=min(seg[idx*2], seg[idx*2+1]);
    }
}

int query(int idx, int begin, int end, int l, int mini)
{
    if(end<l)
        return N+1;
    if(begin>=l && seg[idx]>=mini)
        return N+1;
    if(begin==end)
        return begin;
    int mid=(begin+end)/2;
    int ret=query(idx*2, begin, mid, l, mini);
    if(ret==N+1)
        return query(idx*2+1, mid+1, end, l, mini);
    return ret;
}

int conv(char c)
{
    if(c=='(')
        return 1;
    return -1;
}

const int offs=500005;

int get_occ(int l, int r, int x)
{
    if(r<l)
        return 0;
    return upper_bound(pos[x+offs].begin(), pos[x+offs].end(), r)-
           lower_bound(pos[x+offs].begin(), pos[x+offs].end(), l);
}

int main()
{
    scanf("%d", &N);
    scanf("%s", S);
    sa.build(S, N);
    for(int i=1; i<=N; i++)
    {
        sum[i]=sum[i-1]+conv(S[i-1]);
        pos[sum[i]+offs].push_back(i);
    }
    build(1, 1, N);
    long long ans=0;
    for(int i=0; i<N; i++)
    {
        int len;
        if(i<N-1)
            len=sa.lcp[i];
        else
            len=0;
        int r=query(1, 1, N, sa[i]+1, sum[sa[i]]);
        ans+=get_occ(sa[i]+1+len, r-1, sum[sa[i]]);
    }
    printf("%lld\n", ans);
    return 0;
}