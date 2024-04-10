#pragma GCC optimize(2)
#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
long long n,a[300001],ans,num,res[31][2],ch[300001*30][2],tot;
vector<int> v[300001*30];
inline long long read()
{
    long long x=0;
    char c=getchar();
    while(c<'0'||c>'9')
        c=getchar();
    while(c>='0'&&c<='9')
    {
        x=(x<<1)+(x<<3)+(c^48);
        c=getchar();
    }
    return x;
}
inline void insert(long long x,long long num)
{
    int node=1;
    for(register int i=30;~i;--i)
    {
        if(!ch[node][(x>>i)&1])
            ch[node][(x>>i)&1]=++tot;
        node=ch[node][(x>>i)&1];
        v[node].push_back(num);
    }
}
void dfs(long long k,int deep)
{
    if(ch[k][0])
        dfs(ch[k][0],deep-1);
    if(ch[k][1])
        dfs(ch[k][1],deep-1);
    if(!ch[k][0]||!ch[k][1])
        return;
    long long tmp=0;
    for(register int i=0,j=0;i<(int)v[ch[k][0]].size();++i)
    {
        while(j<(int)v[ch[k][1]].size()&&v[ch[k][0]][i]>v[ch[k][1]][j])
            ++j;
        tmp+=j;
    }
    res[deep][0]+=tmp;
    res[deep][1]+=(long long)v[ch[k][0]].size()*v[ch[k][1]].size()-tmp;
}
int main()
{
    tot=1;
    n=read();
    for(register int i=1;i<=n;++i)
    {
        a[i]=read();
        insert(a[i],i);
    }
    dfs(1,31);
    for(register int i=30;~i;--i)
    {
        if(res[i][0]<=res[i][1])
            num+=res[i][0];
        else
        {
            num+=res[i][1];
            ans|=1ll<<i;
        }
    }
    printf("%lld %lld\n",num,ans>>1);
    return 0;
}