#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int main()
{
    long long n,l,r,x,c[20],i,p,s,cnt=0,j;
    vector < long > v;
    cin>>n>>l>>r>>x;
    for(i=0;i<n;++i)
    cin>>c[i];
    sort(c,c+n);
    p=(1<<n);
    for(i=1;i<p;++i)
    {
        v.clear();
        s=0;
        for(j=0;j<n;++j)
        if(i&(1<<j))
        {v.pb(c[j]);
        s+=c[j];}
        if(v.size()<2) continue;
        if(s<l || s>r) continue;
        if(v[v.size()-1]-v[0]<x) continue;
        cnt++;
    }
    cout<<cnt;
    return 0;
}