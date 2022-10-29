#include <bits/stdc++.h>
#define pb push_back
#define long long long
#define pll pair < long , long >
#define vll vector < pll >
#define vl vector < long >
#define io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int main()
{
    io
    long n,i,x,ans=1,t=-1,h[2002]={0},g=0,j;
    vll v;
    cin>>n;
    for(i=0;i<n;++i)
    {
        cin>>x;
        v.pb({x,i+1});
        h[x]++;
        if(h[x]>=2) g++;
    }
    if(g<=1) {cout<<"NO";exit(0);}
    cout<<"YES"<<endl;
    sort(v.begin(),v.end());
    for(i=0;i<v.size();++i)
    cout<<v[i].second<<" ";
    cout<<endl;
    for(i=0;i<v.size()-1;++i)
    if(v[i].first==v[i+1].first)
    {swap(v[i],v[i+1]),j=i;break;}
    for(i=0;i<v.size();++i)
    cout<<v[i].second<<" ";
    cout<<endl;
    for(i=j+1;i<v.size()-1;++i)
    if(v[i].first==v[i+1].first)
    {swap(v[i],v[i+1]);break;}
    for(i=0;i<v.size();++i)
    cout<<v[i].second<<" ";
    cout<<endl;
    return 0;
}