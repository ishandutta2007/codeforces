#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#define MN 100000
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,a[MN+5],rk[MN+5],s[MN+5],id[MN+5],ans=0;
vector<int> v[MN+5];
bool cmp(int x,int y){return a[x]<a[y];}
inline int getfa(int x){return s[x]?s[x]=getfa(s[x]):x;}
int main()
{
    n=read();
    for(int i=1;i<=n;++i) a[i]=read(),rk[i]=i;
    sort(rk+1,rk+n+1,cmp);
    for(int i=1;i<=n;++i)
        if(getfa(i)!=getfa(rk[i])) s[getfa(i)]=getfa(rk[i]);
    for(int i=1;i<=n;++i) v[getfa(i)].push_back(i),ans+=(getfa(i)==i);
    printf("%d\n",ans);
    for(int i=1;i<=n;++i) if(v[i].size())
    {
        printf("%d ",v[i].size());
        for(int j=0;j<v[i].size();++j)
            printf("%d%c",v[i][j],j+1==v[i].size()?'\n':' ');
    }
    return 0;
}