#include <bits/stdc++.h>

#ifdef getchar
#undef getchar
#endif
#define getchar() (*_pinp?*_pinp++:(_inp[fread(_pinp=_inp, 1, 4096, stdin)]='\0', *_pinp++))
char _inp[4097], *_pinp=_inp;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#ifdef putchar
#undef putchar
#endif
#define putchar(x) (*_pout++=(x), (_pout==_eout?(fwrite(_pout=_out, 1, 4096, stdout)):0))
#define flush() fwrite(_out, 1, _pout-_out, stdout)
char _out[4097], *_eout=_out+4096, *_pout=_out;
#define print(x) do{if(!x)putchar('0');else{for(;x;x/=10)*_p++='0'+x%10;do putchar(*--_p);while(_p!=_buf);}}while(0)
char _buf[20], *_p=_buf;

using namespace std;

template<class Key, class Mapped>
struct bad_map
{
    int sz;
    pair<Key, Mapped> data[6];
    inline void clear()
    {
        sz=0;
    }
    inline pair<Key, Mapped>* find(Key k)
    {
        for(int i=0; i<sz; i++)
            if(data[i].first==k)
                return data+i;
        return nullptr;
    }
    inline constexpr pair<Key, Mapped>* end()
    {
        return nullptr;
    }
    inline Mapped& operator[] (Key k)
    {
        data[sz++]=make_pair(k, Mapped());
        return data[sz-1].second;
    }
};

int Q, N;
long long D[81];
bad_map<pair<long long, long long>, int> cache[81];

inline int solve(int order, long long u, long long v)
{
    if(u==v)
        return 0;
    if(order==1)
        return 1;
    if(u>v)
        swap(u, v);
    auto it=cache[order].find({u, v});
    if(it!=cache[order].end())
        return it->second;
    int& ret=cache[order][{u, v}];
    ret=0x3f3f3f3fLL;
    if(u>D[order-1] && v>D[order-1])
        ret=min(ret, solve(order-2, u-D[order-1], v-D[order-1]));
    else if(u<=D[order-1] && v<=D[order-1])
    {
        ret=min(ret, solve(order-1, u, v));
        ret=min(ret, solve(order-1, u, 1)+2+solve(order-1, D[order-1], v));
        ret=min(ret, solve(order-1, u, D[order-1])+2+solve(order-1, 1, v));
    }
    else
    {
        ret=min(ret, solve(order-1, u, 1)+1+solve(order-2, 1, v-D[order-1]));
        ret=min(ret, solve(order-1, u, D[order-1])+1+solve(order-2, 1, v-D[order-1]));
    }
    return ret;
}

int main()
{
    scan(Q);
    scan(N);
    N=min(N, 80);
    D[0]=1;
    D[1]=2;
    for(int i=2; i<=N; i++)
        D[i]=D[i-1]+D[i-2];
    long long a, b;
    while(Q--)
    {
        scan(a);
        scan(b);
        int ans=solve(lower_bound(D, D+N-1, max(a, b))-D+1, a, b);
        print(ans);
        putchar('\n');
        for(int i=3; i<=N; i++)
            cache[i].clear();
    }
    flush();
    return 0;
}