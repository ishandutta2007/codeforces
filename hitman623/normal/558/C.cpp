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
int n,a[100005],i,ans=1e9,cur,d,f,j,vi[1000006];
int main()
{
    io
    vl v;
    cin>>n;
    for(i=0;i<n;++i)
    cin>>a[i];
    sort(a,a+n);
    d=a[0];
    set < int > s;
    while(d)
    {
        v.pb(d);
        d/=2;
    }
    d=v.size();
    for(i=0;i<d;++i)
    {
        cur=2*v[i];
        while(cur<=2e5)
        {
            v.pb(cur);
            cur*=2;
        }
    }
    for(i=0;i<v.size();++i)
    s.insert(v[i]);
    v.clear();
    for(auto i:s)
    v.pb(i);
    for(i=0;i<v.size();++i)
    {
        vl vv;
        d=v[i];
        int cnt=0;
        f=1;
        while(d>0)
        {
            vi[d]=1;
            d/=2;
        }
        cur=v[i];
        for(j=0;j<n;++j)
        {
            d=a[j];
            while(d && !vi[d])
            d/=2,cnt++;
            if(d==0) {f=0;break;}
            while(d<cur)
            d*=2,cnt++;
            if(d!=cur) {f=0;break;}
        }
        if(f) ans=min(ans,cnt);
        d=v[i];
        while(d>0)
        {
            vi[d]=0;
            d/=2;
        }
    }
    cout<<ans;
    return 0;
}