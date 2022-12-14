#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<cstdio>
#include<queue>
#include<cmath>
#include<map>
#include<set>
#define MN 100000
#define pa pair<int,int>
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
long long ans=1e12,mn[MN*10+5],C[MN+5],tot;
vector<pa> v[MN*10+5],V[MN*10+5];
int n,m,K;
int main()
{
    n=read();m=read();K=read();mn[0]=1e12;tot=(long long)1e12 * n;
    for(int i=1;i<=m;++i)
    {
        int d=read(),f=read(),t=read(),c=read();
        if(!f) v[d].push_back(make_pair(t,c));
        else V[d].push_back(make_pair(f,c));
    }
    for(int i=1;i<=n;++i) C[i]=(long long)1e12;
    for(int i=1;i<=1000000;++i)
    {
        mn[i]=mn[i-1];
        for(int j=0;j<V[i].size();++j)
        {
            tot-=C[V[i][j].first];
            C[V[i][j].first]=min(C[V[i][j].first],(long long)V[i][j].second);
            tot+=C[V[i][j].first];
        }
        mn[i]=min(mn[i],tot);
    }
    tot=(long long)1e12 * n;
    for(int i=1;i<=n;++i) C[i]=(long long)1e12;
    for(int i=1000000;i-K-1>=1;--i)
    {
        for(int j=0;j<v[i].size();++j)
        {
            tot-=C[v[i][j].first];
            C[v[i][j].first]=min(C[v[i][j].first],(long long)v[i][j].second);
            tot+=C[v[i][j].first];
        }
        ans=min(ans,tot+mn[i-K-1]);
    }
    printf("%lld\n",ans>1e11?-1:ans);
    return 0;
}