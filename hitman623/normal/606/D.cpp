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
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
long n,m,a[100005],b[100005],i,term,k,in,d,c[100005]={0},j,x,y;
map < long ,pll > edges;
vll vv;
vector < pair < long , pll > > v;
int main()
{
    io
    cin>>n>>m;
    for(i=0;i<m;++i)
    {
        cin>>a[i]>>b[i];
        if(b[i])
        vv.pb({a[i],i});
        v.pb({a[i],{b[i],i}});
    }
    sort(vv.begin(),vv.end());
    for(i=0;i<vv.size();++i)
    edges[vv[i].y]={1,i+2};
    sort(v.begin(),v.end());
    j=0;
    k=1;
    for(i=0;i<v.size();++i)
    if(v[i].y.x==0)
    {
        if(v[i].x<vv[k].x) {cout<<-1;exit(0);}
        edges[v[i].y.y]={j+2,k+2};
        j++;
        if(j==k) k++,j=0;
    }
    for(i=0;i<m;++i)
    cout<<edges[i].x<<" "<<edges[i].y<<"\n";
    return 0;
}