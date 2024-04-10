#include <bits/stdc++.h>

using namespace std;

const int HASH_MAXN=5001;
const int X=129;
const int MOD1=1000000009;
const int MOD2=1000000021;
int P1[HASH_MAXN];
int P2[HASH_MAXN];

struct Hash
{
    int len, val0, val1;
    Hash()
    {
        //
    }
    Hash(int val):
        len(1),
        val0(val),
        val1(val)
    {
        //
    }
    Hash operator+ (const Hash& other) const
    {
        Hash ret;
        ret.len=len+other.len;
        ret.val0=(other.val0+1LL*P1[other.len]*val0)%MOD1;
        ret.val1=(other.val1+1LL*P2[other.len]*val1)%MOD2;
        return ret;
    }
    Hash operator- (const Hash& other) const
    {
        Hash ret;
        ret.len=len-other.len;
        ret.val0=val0-1LL*P1[len-other.len]*other.val0%MOD1;
        if(ret.val0<0)
            ret.val0+=MOD1;
        ret.val1=val1-1LL*P2[len-other.len]*other.val1%MOD2;
        if(ret.val1<0)
            ret.val1+=MOD2;
        return ret;
    }
    bool operator< (const Hash& other) const
    {
        if(len!=other.len)
            return len<other.len;
        if(val0!=other.val0)
            return val0<other.val0;
        return val1<other.val1;
    }
    bool operator== (const Hash& other) const
    {
        return len==other.len && val0==other.val0 && val1==other.val1;
    }
    bool operator!= (const Hash& other) const
    {
        return !(*this==other);
    }
};

Hash make_hash(int v)
{
    Hash ret;
    ret.val0=ret.val1=v;
    ret.len=1;
    return ret;
}

void init_hash()
{
    P1[0]=1;
    for(int i=1; i<HASH_MAXN; i++)
        P1[i]=1LL*P1[i-1]*X%MOD1;
    P2[0]=1;
    for(int i=1; i<HASH_MAXN; i++)
        P2[i]=1LL*P2[i-1]*X%MOD2;
}

static int _hash_initialized=(init_hash(), 0);

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

int N, K;
char S[5001];
vector<pair<int, int>> all;
Hash P[5001];
int lcp[5001][5001];

Hash get(int a, int b)
{
    if(a==0)
        return P[b];
    return P[b]-P[a-1];
}

int get_lcp(int a, int b, int l1, int l2)
{
    if(S[a]!=S[b])
        return 0;
    int lo=1, mid, hi=min(l1, l2);
    while(lo<hi)
    {
        mid=(lo+hi+1)/2;
        if(get(a, a+mid-1)==get(b, b+mid-1))
            lo=mid;
        else
            hi=mid-1;
    }
    return lo;
    if(lo<min(l1, l2))
        return S[a+lo]<S[b+lo];
    return lo==l1 && l1!=l2;
}

bool cmp(int a, int b, int l1, int l2)
{
    int l=min(lcp[a][b], min(l1, l2));
    if(l<min(l1, l2))
        return S[a+l]<S[b+l];
    return l==l1 && l1!=l2;
}

int main()
{
    scanf("%s%d", S, &K);
    N=strlen(S);
    for(int i=0; i<N; i++)
    {
        P[i]=P[i-1]+make_hash(S[i]);
        int j=1;
        while(i-j+1>=0 && i+j-1<N && S[i-j+1]==S[i+j-1])
        {
            all.push_back({i-j+1, j*2-1});
            j+=2;
        }
        j=2;
        while(i-j+1>=0 && i+j-1<N && S[i-j+1]==S[i+j-1])
        {
            all.push_back({i-j+1, j*2-1});
            j+=2;
        }
        j=1;
        while(i-j+1>=0 && i+j<N && S[i-j+1]==S[i+j])
        {
            all.push_back({i-j+1, j*2});
            j+=2;
        }
        j=2;
        while(i-j+1>=0 && i+j<N && S[i-j+1]==S[i+j])
        {
            all.push_back({i-j+1, j*2});
            j+=2;
        }
    }
    suffix_array sa;
    sa.build(S, N);
    for(int i=0; i<N-1; i++)
    {
        lcp[i][i]=N-i;
        int t=lcp[sa[i]][sa[i+1]]=lcp[sa[i+1]][sa[i]]=sa.lcp[i];
        for(int j=i+2; j<N; j++)
            t=lcp[sa[i]][sa[j]]=lcp[sa[j]][sa[i]]=min(t, sa.lcp[j-1]);
    }
    lcp[N-1][N-1]=1;
    nth_element(all.begin(), all.begin()+K-1, all.end(), [](pair<int, int> a, pair<int, int> b) {
        return cmp(a.first, b.first, a.second, b.second);
    });
    printf("%.*s\n", all[K-1].second, S+all[K-1].first);
    return 0;
}