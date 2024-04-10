#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define forinc(a,b,c) for(int a=b,_c=c;a<=_c;++a)
#define fordec(a,b,c) for(int a=b,_c=c;a>=_c;--a)
#define forv(a,b) for(auto&a:b)
#define pb push_back
using namespace std;
const int N=400010;
int n,q,tin[N],tout[N],x[N],dd[N],id,it,in[N];
vector<int> ke[N];
void DFS(int u)
{
    dd[u]=1;
    tin[u]=++id;
    x[++it]=u;in[u]=it;
    forv(v,ke[u]) if(!dd[v]) DFS(v);
    tout[u]=++id;
}
bool cheq(int u,int v)
{
    if(!u||!v) return 0;
    return (tin[u]<=tin[v]&&tout[u]>=tout[v]);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    //freopen("E.inp","r",stdin);
    cin>>n>>q;
    forinc(v,2,n)
    {
        int u;cin>>u;
        ke[u].pb(v);
    }
    DFS(1);
    while(q--)
    {
        int u,k;
        cin>>u>>k;
        int st=in[u];
        int v=x[st+k-1];
        if(cheq(u,v)) cout<<v<<"\n";
        else cout<<-1<<"\n";
    }
}