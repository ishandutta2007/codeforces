#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
struct edge
{
    int nxt,to,weight;
}e[200001<<1];
int n,tot,h[200001],a[200001],s[200001],maxn;
long long ans[200001];
vector<int> node[200001];
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
inline int gcd(int x,int y)
{
    return x%y? gcd(y,x%y):y;
}
inline void add(int x,int y,int w)
{
    e[++tot].nxt=h[x];
    h[x]=tot;
    e[tot].to=y;
    e[tot].weight=w;
}
void dfs(int k,int f,int val)
{
    s[k]=1;
    for(int i=h[k];i;i=e[i].nxt)
    {
        if(e[i].to==f||e[i].weight%val)
            continue;
        dfs(e[i].to,k,val);
        s[k]+=s[e[i].to];
    }
}
int main()
{
    n=read();
    for(int i=1;i<=n;++i)
    {
        maxn=max(maxn,a[i]=read());
        for(int j=1;j*j<=a[i];++j)
            if(a[i]%j==0)
            {
                node[j].emplace_back(i);
                if(j*j!=a[i])
                    node[a[i]/j].emplace_back(i);
            }
    }
    for(int i=1;i<n;++i)
    {
        int x=read(),y=read();
        add(x,y,gcd(a[x],a[y]));
        add(y,x,gcd(a[x],a[y]));
    }
    for(int i=1;i<=maxn;++i)
    {
        for(auto j:node[i])
            if(!s[j])
            {
                dfs(j,0,i);
                ans[i]+=1ll*s[j]*(s[j]+1)/2;
            }
        for(auto j:node[i])
            s[j]=0;
    }
    for(int i=maxn;i>=1;--i)
        for(int j=i+i;j<=maxn;j+=i)
            ans[i]-=ans[j];
    for(int i=1;i<=maxn;++i)
        if(ans[i])
            cout<<i<<" "<<ans[i]<<'\n';
    return 0;
}