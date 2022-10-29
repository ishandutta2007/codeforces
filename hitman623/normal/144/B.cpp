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
    long xa,ya,xb,yb,n,i,x[1004],y[1004],r[1004],c=0,xx,yy,j;
    cin>>xa>>ya>>xb>>yb;
    cin>>n;
    for(i=0;i<n;i++)
    cin>>x[i]>>y[i]>>r[i];
    if(xa>xb) swap(xa,xb);
    if(ya>yb) swap(ya,yb);
    for(i=xa;i<=xb;++i)
    {
        xx=i;
        yy=ya;
        for(j=0;j<n;++j)
        if((x[j]-xx)*(x[j]-xx)+(y[j]-yy)*(y[j]-yy)<=r[j]*r[j])
        break;
        if(j==n) c++;
    }
    for(i=xa;i<=xb;++i)
    {
        xx=i;
        yy=yb;
        for(j=0;j<n;++j)
        if((x[j]-xx)*(x[j]-xx)+(y[j]-yy)*(y[j]-yy)<=r[j]*r[j])
        break;
        if(j==n) c++;
    }
    for(i=ya+1;i<yb;++i)
    {
        xx=xa;
        yy=i;
        for(j=0;j<n;++j)
        if((x[j]-xx)*(x[j]-xx)+(y[j]-yy)*(y[j]-yy)<=r[j]*r[j])
        break;
        if(j==n) c++;
    }
    for(i=ya+1;i<yb;++i)
    {
        xx=xb;
        yy=i;
        for(j=0;j<n;++j)
        if((x[j]-xx)*(x[j]-xx)+(y[j]-yy)*(y[j]-yy)<=r[j]*r[j])
        break;
        if(j==n) c++;
    }
    cout<<c;
    return 0;
}