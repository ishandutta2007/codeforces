#include <bits/stdc++.h>
#define pb push_back
#define long long long
#define pll pair < long , long >
#define vll vector < pll >
#define ml map < long , long >
#define mll map < pll , long >
#define x first
#define y second
#define vl vector < long >
#define io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
long n,m,i,t,x,y,r[100005],j,entry[100005]={0},exi[100005],tim=1,A,B,C;
vl a[100005];
vll q,p;
long root(long x)
{
    if(r[x]==x) return x;
    else return r[x]=root(r[x]);
}
long dfs(long node , long par)
{
    long i;
    entry[node]=tim++;
    for(i=0;i<a[node].size();++i)
    if(a[node][i]!=par)
    dfs(a[node][i],node);
    exi[node]=tim++;
}

int main()
{
    io
    cin>>n>>m;
    for(i=1;i<=n;++i)
    r[i]=i;
    for(i=0;i<m;++i)
    {
        cin>>t;
        switch(t)
        {
            case 1:
            cin>>x>>y;
            a[x].pb(y);
            a[y].pb(x);
            r[x]=root(y);
            break;
            case 2:
            cin>>x;
            p.pb({root(x),x});
            break;
            case 3:
            cin>>x>>y;
            q.pb({x,y-1});
        }
    }
    for(i=1;i<=n;++i)
    if(entry[i]==0)
    dfs(root(i),-1);
    for(i=0;i<q.size();++i)
    {
        A=p[q[i].second].first;
        B=q[i].first;
        C=p[q[i].second].second;
        if(entry[A]<=entry[B] && exi[A]>=exi[B] && exi[B]>=exi[C] && entry[B]<=entry[C])
        cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}