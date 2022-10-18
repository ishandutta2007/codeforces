#include<iostream>
#include<cstdio>
#include<set>
using namespace std;
int n,fa[31][100001],pos[100001],maxn,a[100001],d[100001],cnt,p[100001],ans[100001];
set<int> s[100001],st;
inline int read()
{
    int x=0;
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
int main()
{
    n=read();
    for(int i=1;i<=n;++i)
        ++d[fa[0][i]=read()];
    for(int i=1;i<=30;++i)
        for(int j=1;j<=n;++j)
            fa[i][j]=fa[i-1][fa[i-1][j]];
    for(int i=1;i<=n;++i)
    {
        maxn=max(a[i]=read(),maxn);
        if(a[i]<=n)
            p[a[i]]=i;
        cnt+=!d[i];
        pos[i]=i;
    }
    maxn=(maxn-n)/cnt;
    for(int i=30;~i;--i)
        if(maxn>>i&1)
            for(int j=1;j<=n;++j)
                pos[j]=fa[i][pos[j]];
    for(int i=1;i<=n;++i)
        s[pos[i]].emplace(i);
    for(int i=1;i<=n;++i)
        if(p[i])
        {
            ans[*s[p[i]].begin()]=i;
            s[p[i]].erase(s[p[i]].begin());
            st.insert(s[p[i]].begin(),s[p[i]].end());
        }
        else
        {
            ans[*st.begin()]=i;
            st.erase(st.begin());
        }
    for(int i=1;i<=n;++i)
        cout<<ans[i]<<" ";
    cout<<'\n';
    return 0;
}