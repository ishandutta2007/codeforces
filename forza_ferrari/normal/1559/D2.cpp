#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int n,m1,m2,ans;
vector<pair<int,int> > e;
vector<int> l,r;
struct tree
{
    int bin[100001];
    int anc(int k)
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
}T1,T2;
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
void print(int x)
{
    if(x>=10)
        print(x/10);
    putchar(x%10+'0');
}
int main()
{
    n=read(),m1=read(),m2=read();
    for(register int i=1;i<=m1;++i)
    {
        int x=read(),y=read();
        T1.link(x,y);
    }
    for(register int i=1;i<=m2;++i)
    {
        int x=read(),y=read();
        T2.link(x,y);
    }
    for(register int i=2;i<=n;++i)
        if(T1.anc(1)!=T1.anc(i)&&T2.anc(1)!=T2.anc(i))
        {
            T1.link(1,i);
            T2.link(1,i);
            ++ans;
            e.push_back(make_pair(1,i));
        }
    for(register int i=2;i<=n;++i)
    {
        if(T1.anc(1)!=T1.anc(i))
        {
            T1.link(1,i);
            r.push_back(i);
        }
        if(T2.anc(1)!=T2.anc(i))
        {
            T2.link(1,i);
            l.push_back(i);
        }
    }
    for(register int i=0;i<(int)min(l.size(),r.size());++i)
    {
        ++ans;
        e.push_back(make_pair(l[i],r[i]));
    }
    print(ans);
    putchar('\n');
    for(register int i=0;i<(int)e.size();++i)
    {
        print(e[i].first);
        putchar(' ');
        print(e[i].second);
        putchar('\n');
    }
    return 0;
}