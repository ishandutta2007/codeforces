#include <bits/stdc++.h>
#define pb push_back
#define long long long
using namespace std;
int main()
{
    long n,r,avg,i,a[100005],b[100005],s=0,c=0,ans=0;
    vector < pair < long , long > > v;
    cin>>n>>r>>avg;
    for(i=0;i<n;++i)
    {
        cin>>a[i]>>b[i];
        s+=a[i];
        v.pb({b[i],r-a[i]});
    }
    c=n*avg-s;
    if(c<=0) {cout<<0;exit(0);}
    sort(v.begin(),v.end());
    i=0;
    while(c>0 && i<v.size())
    {
        if(c>v[i].second)
        {
            c-=v[i].second;
            ans+=v[i].second*v[i].first;
        }
        else
        {
            ans+=v[i].first*c;
            c=0;
        }
        i++;
    }
    cout<<ans;
    return 0;
}