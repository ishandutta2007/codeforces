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
long n,a[2003][2003],i,j,ld[4005]={0},rd[4005]={0},m1=0,m2=0,x1,x2,y1,y2;
int main()
{
    io
    cin>>n;
    for(i=1;i<=n;++i)
    for(j=1;j<=n;++j)
    cin>>a[i][j];
    for(i=1;i<=n;++i)
    for(j=1;j<=n;++j)
    {
        rd[i-j+n]+=a[i][j];
        ld[i+j]+=a[i][j];
    }
    for(i=1;i<=n;++i)
    for(j=1;j<=n;++j)
    {
        if(m1<=rd[i-j+n]+ld[i+j]-a[i][j])
        {
            m1=rd[i-j+n]+ld[i+j]-a[i][j];
            x1=i,y1=j;
        }
    }
    for(i=1;i<=n;++i)
    for(j=1;j<=n;++j)
    if((abs(i-x1)+abs(j-y1))%2)
    {
        if(m2<=rd[i-j+n]+ld[i+j]-a[i][j])
        {
            m2=rd[i-j+n]+ld[i+j]-a[i][j];
            x2=i,y2=j;
        }
    }
    cout<<m1+m2<<"\n";
    cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2;
    return 0;
}