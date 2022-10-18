#include<iostream>
#include<cstdio>
#include<set>
using namespace std;
int t,n,m,bin[200001],x,y,z;
pair<int,int> a[200005];
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
inline int anc(int k)
{
    if(!bin[k])
        return k;
    return bin[k]=anc(bin[k]);
}
inline void link(int x,int y)
{
    x=anc(x);
    y=anc(y);
    if(x^y)
        bin[y]=x;
}
int main()
{
    t=read();
    while(t--)
    {
        n=read(),m=read();
        for(int i=1;i<=n;++i)
            bin[i]=0;
        x=y=z=0;
        set<int> s;
        for(int i=1;i<=m;++i)
        {
            a[i].first=read(),a[i].second=read();
            if(anc(a[i].first)==anc(a[i].second))
            {
                if(!x)
                    x=i;
                else if(!y)
                    y=i;
                else
                    z=i;
                s.emplace(a[i].first);
                s.emplace(a[i].second);
            }
            else
                link(a[i].first,a[i].second);
        }
        if(m==n+2)
            if(s.size()==3)
            {
                for(int i=1;i<=n;++i)
                    bin[i]=0;
                link(a[z].first,a[z].second);
                int tmp=z;
                z=0;
                for(int i=1;i<=m;++i)
                {
                    if(i==x||i==y||i==tmp)
                        continue;
                    if(anc(a[i].first)==anc(a[i].second))
                    {
                        z=i;
                        break;
                    }
                    link(a[i].first,a[i].second);
                }
            }
        for(int i=1;i<=m;++i)
            cout<<(i==x||i==y||i==z);
        cout<<'\n';
    }
    return 0;
}