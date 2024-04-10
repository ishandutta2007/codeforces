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
    vll v(8);
    long i,x[3],y[3];
    for(i=0;i<8;++i)
    cin>>v[i].first>>v[i].second;
    sort(v.begin(),v.end());
    if(v[0].first!=v[1].first || v[1].first!=v[2].first) {cout<<"ugly";exit(0);}
    x[0]=v[0].first;
    y[0]=v[0].second;
    y[1]=v[1].second;
    y[2]=v[2].second;
    if(v[3].second!=y[0] || v[4].second!=y[2] || v[3].first!=v[4].first)   {cout<<"ugly";exit(0);}
    x[1]=v[4].first;
    if(v[5].first!=v[6].first || v[6].first!=v[7].first) {cout<<"ugly";exit(0);}
    if(v[5].second!=y[0] || v[6].second!=y[1] || v[7].second!=y[2]) {cout<<"ugly";exit(0);}
    x[2]=v[5].first;
    if(y[0]>=y[1] || y[1]>=y[2] || x[0]>=x[1] || x[1]>=x[2]) cout<<"ugly";
    else cout<<"respectable";
    return 0;
}