#include <bits/stdc++.h>
#define pb push_back

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long n,m,b,g,hb[101]={0},hg[101]={0},i,x;
    cin>>n>>m;
    cin>>b;
    for(i=0;i<b;++i)
    {cin>>x;
    hb[x]=1;}
    cin>>g;
    for(i=0;i<g;++i)
    {cin>>x;
    hg[x]=1;}
    for(i=0;i<n*m*n*m;++i)
    {
        if(hb[i%n] || hg[i%m])
        {
            hb[i%n]=1;
            hg[i%m]=1;
        }
    }
    for(i=0;i<n;++i)
    if(hb[i]!=1) {cout<<"No";exit(0);}
    for(i=0;i<m;++i)
    if(hg[i]!=1) {cout<<"No";exit(0);}
    cout<<"Yes";
    return 0;
}