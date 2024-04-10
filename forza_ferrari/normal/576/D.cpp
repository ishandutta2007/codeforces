#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<bitset>
using namespace std;
int n,m,node[151],bin[151],cnt;
vector<pair<int,int> > v[151];
struct edge
{
    int x,y,w;
}a[151];
struct matrix
{
    bitset<151> a[151];
    matrix()
    {
        for(int i=1;i<=n;++i)
            a[i].reset();
    }
    inline void init()
    {
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
                a[i][j]=i==j;
    }
}w,e;
inline matrix operator *(matrix x,matrix y)
{
    matrix res;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            if(x.a[i][j])
                res.a[i]|=y.a[j];
    return res;
}
inline matrix pw(matrix a,int b)
{
    matrix res;
    res.init();
    while(b)
    {
        if(b&1)
            res=res*a;
        b>>=1;
        a=a*a;
    }
    return res;
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
    cin>>n>>m;
    for(int i=1;i<=m;++i)
    {
        cin>>a[i].x>>a[i].y>>a[i].w;
        node[i]=a[i].w;
    }
    sort(node+1,node+m+1);
    cnt=unique(node+1,node+m+1)-node-1;
    if(node[1])
    {
        cout<<"Impossible\n";
        return 0;
    }
    for(int i=1;i<=m;++i)
    {
        a[i].w=lower_bound(node+1,node+cnt+1,a[i].w)-node;
        v[a[i].w].emplace_back(a[i].x,a[i].y);
    }
    w.a[1][1]=1;
    for(int i=1;i<=cnt;++i)
    {
        for(auto j:v[i])
        {
            e.a[j.first][j.second]=1;
            link(j.first,j.second);
        }
        if(anc(1)==anc(n))
        {
            int p=i+1;
            for(int j=node[i]+1;j<=node[i]+n;++j)
            {
                w=w*e;
                if(w.a[1][n])
                {
                    cout<<j<<'\n';
                    return 0;
                }
                if(p<=cnt&&j==node[p])
                {
                    for(auto k:v[p])
                    {
                        e.a[k.first][k.second]=1;
                        link(k.first,k.second);
                    }
                    ++p;
                }
            }
            cout<<"Impossible\n";
            return 0;
        }
        if(i==cnt)
        {
            cout<<"Impossible\n";
            return 0;
        }
        w=w*pw(e,node[i+1]-node[i]);
    }
    cout<<"Impossible\n";
    return 0;
}