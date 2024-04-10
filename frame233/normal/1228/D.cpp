// Author -- Frame

#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<iostream>
#include<queue>

#define lowbit(x) ((x)&(-x))
#define Finline __inline__ __attribute__ ((always_inline))
#define DEBUG printf("Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x7fffffffffffffff;
const double eps=1e-10;

uint seed=19260817;
const uint _RAND_MAX_=4294967295u;
Finline uint Rand(){return seed=seed*998244353u+1000000007u;}

template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(a>b)&&(a=b);}
template <typename _Tp>Finline bool _cmp(const _Tp &a,const _Tp &b){return abs(a-b)<=eps;}
template <typename _Tp>Finline void read(_Tp& x)
{
    register char ch(getchar());
    bool f(false);
    while(ch<48||ch>57) f|=ch==45,ch=getchar();
    x=ch&15,ch=getchar();
    while(ch>=48&&ch<=57) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
    if(f) x=-x;
}
template <typename _Tp,typename... Args>Finline void read(_Tp &t,Args &...args)
{
    read(t);read(args...);
}
Finline int read_str(char *s)
{
    register char ch(getchar());
    while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
    register char *tar=s;
    *tar=ch,ch=getchar();
    while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
    return tar-s+1;
}

const int N=300005;
std::vector<int> v[N];
bool used[N];
int col[N];
int cnt[4];
int main()
{
    int n,m;
    read(n,m);
    int x,y;
    for(int i=1;i<=m;++i)
    {
        read(x,y);
        v[x].emplace_back(y);
        v[y].emplace_back(x);
    }
    int id=1;
    std::queue<int> q;
    while(!q.empty()) q.pop();
    memset(used,0,sizeof(used));
    for(int i=1;i<=n;++i)
    {
        if(!col[i])
        {
            q.push(i);
        }
    }
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        while(!q.empty()&&used[x])
        {
            x=q.front();
            q.pop();
        }
        if(used[x]) break;
        col[x]=id;
        for(auto it:v[x])
        {
            used[it]=1;
        }
    }
    ++id;
    while(!q.empty()) q.pop();
    memset(used,0,sizeof(used));
    for(int i=1;i<=n;++i)
    {
        if(!col[i])
        {
            q.push(i);
        }
    }
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        while(!q.empty()&&used[x])
        {
            x=q.front();
            q.pop();
        }
        if(used[x]) break;
        col[x]=id;
        for(auto it:v[x])
        {
            used[it]=1;
        }
    }
    ++id;
    while(!q.empty()) q.pop();
    memset(used,0,sizeof(used));
    for(int i=1;i<=n;++i)
    {
        if(!col[i])
        {
            q.push(i);
        }
    }
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        while(!q.empty()&&used[x])
        {
            x=q.front();
            q.pop();
        }
        if(used[x]) break;
        used[x]=1;
        col[x]=id;
        for(auto it:v[x])
        {
            used[it]=1;
        }
    }
    for(int i=1;i<=n;++i)
    {
        if(!col[i])
        {
            printf("-1\n");
            return 0;
        }
    }

    for(int i=1;i<=n;++i)
    {
        ++cnt[col[i]];
    }
    if(!cnt[3]||!cnt[1]||!cnt[2])
    {
        printf("-1\n");
        return 0;
    }
    for(int i=1;i<=n;++i)
    {
        for(auto it:v[i])
        {
            if(col[i]==col[it])
            {
                printf("-1\n");
                return 0;
            }
        if(n-(int)v[i].size()!=cnt[col[i]])
        {
            printf("-1\n");
            return 0;
        }
        }
    }
    for(int i=1;i<=n;++i)
    {
        printf("%d ",col[i]);
    }
    printf("\n");
    return 0;
}