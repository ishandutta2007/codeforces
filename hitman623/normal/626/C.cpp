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

int main()
{
    io
    long n,m,tw,th,ts,i,nn,mm;
    cin>>n>>m;
    for(i=1;i<=1e7;++i)
    {
        tw=i/2;
        th=i/3;
        ts=i/6;
        tw-=ts;
        th-=ts;
        nn=n;
        mm=m;
        nn-=tw;
        if(nn<0) nn=0;
        mm-=th;
        if(mm<0) mm=0;
        if(nn+mm<=ts) break;
    }
    cout<<i;
    return 0;
}