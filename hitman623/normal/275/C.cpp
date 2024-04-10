#include <bits/stdc++.h>
#define pb push_back
#define long long long
using namespace std;

int main()
{
    long n,k,a[100005],i,ans=0,l=0,mx=0,d,j;
    vector < long > v;
    map < long , long > mp,visi;
    cin>>n>>k;
    for(i=0;i<n;++i)
    {
        cin>>a[i];
        mp[a[i]]=1;
        mx=max(mx,a[i]);
    }
    if(k==1) {cout<<n;exit(0);}
    sort(a,a+n);
    for(i=0;i<n;++i)
    if(!visi[a[i]])
    {
        v.clear();
        d=a[i];
        while(d<=mx)
        {
            if(mp[d])
            {
                v.pb(d);
                visi[d]=1;
            }
            d=d*k;
        }
        ans++;
        l=v[0];
        if(v.size()>1)
        for(j=1;j<v.size();++j)
        if(v[j]==k*l) continue;
        else {ans++;l=v[j];}
    }
    cout<<ans;
    return 0;
}