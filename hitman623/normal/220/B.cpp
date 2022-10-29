#include <bits/stdc++.h>
#define pb push_back
#define long long long
#define pll pair < long , long >
#define vll vector < pll >
#define vl vector < long >
#define io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
vll v,q;
map < pll , long > mp;
long n,m,i,x,y,b[100005],a[100005],ans=0,l,r,j,s;
void add(long x)
{
    if(x>1e5) return ;
    if(b[x]==x) ans--;
    b[x]++;
    if(b[x]==x) ans++;
}
void rem(long x)
{
    if(x>1e5) return ;
    if(b[x]==x) ans--;
    b[x]--;
    if(b[x]==x) ans++;
}
bool cmp(pll a, pll b)
{
    if(a.first/s==b.first/s) return a.second<b.second;
    return a.first/s<b.first/s;
}
int main()
{
    io
    cin>>n>>m;
    s=sqrt(n);
    for(i=0;i<n;++i)
    cin>>a[i];
    for(i=0;i<m;++i)
    {
        cin>>x>>y;
        x--;y--;
        v.pb({x,y});
    }
    q=v;
    sort(v.begin(),v.end(),cmp);
    l=0;
    r=0;
    for(i=0;i<m;++i)
    {
        while(l<v[i].first)
        {
            rem(a[l]);
            l++;
        }
        while(l>v[i].first)
        {
            add(a[l-1]);
            l--;
        }
        while(r<=v[i].second)
        {
            add(a[r]);
            r++;
        }
        while(r>v[i].second+1)
        {
            rem(a[r-1]);
            r--;
        }
        mp[{l,r-1}]=ans;
    }
    for(i=0;i<m;++i)
    cout<<mp[q[i]]<<endl;
    return 0;
}