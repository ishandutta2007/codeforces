#include<iostream>
#include<cstdio>
using namespace std;
int n,m,q,bin[31][100001],val[100001],sum[100001];
bool tag[100001];
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
inline int anc(int id,int k)
{
    if(!bin[id][k])
        return k;
    return bin[id][k]=anc(id,bin[id][k]);
}
inline void link(int id,int x,int y)
{
    x=anc(id,x);
    y=anc(id,y);
    if(x^y)
        bin[id][y]=x;
}
int main()
{
    n=read(),m=read();
    for(int i=1;i<=n;++i)
        val[i]=(1<<30)-1;
    for(int i=1;i<=m;++i)
    {
        int x=read(),y=read(),w=read();
        val[x]&=w;
        val[y]&=w;
        for(int j=0;j<30;++j)
            if(w>>j&1)
                link(j,x,y);
    }
    for(int i=1;i<30;++i)
    {
        for(int j=1;j<=n;++j)
            sum[j]=val[j];
        for(int j=1;j<=n;++j)
            sum[anc(i,j)]&=val[j];
        for(int j=1;j<=n;++j)
            tag[j]|=!sum[anc(i,j)];
    }
    q=read();
    while(q--)
    {
        int x=read(),y=read();
        int cnt=0;
        for(int i=0;i<30;++i)
            cnt+=anc(i,x)==anc(i,y);
        if(cnt)
            cout<<"0\n";
        else if(tag[x])
            cout<<"1\n";
        else
            cout<<"2\n";
    }
    return 0;
}