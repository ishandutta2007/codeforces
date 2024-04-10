#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef vector<int> vct;
typedef pair<int,int> pii;
const int N=1E6+2;
const int inf=1<<30;
ll read()
{
    ll a=0;
    char b=1,c;
    do if((c=getchar())==45)b=-1;while(c<48||c>57);
    do a=(a<<3)+(a<<1)+(c&15);while((c=getchar())>47&&c<58);
    return a*b;
}
void write(ll x,char c)
{
    if(x<0)putchar(45),x=-x;
    char a[20],s=0;
    do a[++s]=x%10|48;while(x/=10);
    do putchar(a[s]);while(--s);
    putchar(c);
}
vct g[N];
int a[N],fa[N];
int find(int x){return fa[x]^x?fa[x]=find(fa[x]):x;}
set<pii>q;
int main()
{
    for(int i=2;i<N;++i)
    {
        if(g[i].empty())
        {
            for(int j=i;j<N;j+=i)
            {
                g[j].pb(i);
            }
        }
        fa[i]=i;
    }
    int n=read(),m=read();
    for(int i=1;i<=n;++i)
    {
        a[i]=read();
        int u=find(a[i]);
        for(int x:g[a[i]])
        {
            int v=find(x);
            if(u^v)fa[v]=u;
        }
    }
    for(int i=1;i<=n;++i)
    {
        vct v=g[a[i]+1];
        v.pb(a[i]);
        for(int &x:v)x=find(x);
        sort(v.begin(),v.end());
        v.erase(unique(v.begin(),v.end()),v.end());
        for(int j=v.size();j--;)
        {
            for(int k=0;k<j;++k)
            {
                q.insert({v[k],v[j]});
            }
        }
    }
    while(m--)
    {
        int u=find(a[read()]),v=find(a[read()]);
        if(u==v)puts("0");
        else
        {
            if(u>v)swap(u,v);
            puts(q.find({u,v})!=q.end()?"1":"2");
        }
    }
}