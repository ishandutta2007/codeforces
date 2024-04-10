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
    long n,m,x,y,z,p,i,xx[100005],yy[100005],xxx,yyy;
    cin>>n>>m>>x>>y>>z>>p;
    for(i=0;i<p;i++)
    cin>>xx[i]>>yy[i];
    x%=4;
    y%=2;
    z%=4;
    if(x==1)
    {
        for(i=0;i<p;++i)
        {
            xxx=xx[i];
            yyy=yy[i];
            xx[i]=yyy;
            yy[i]=n-xxx+1;
        }
        swap(n,m);
    }
    else if(x==2)
    {
        for(i=0;i<p;++i)
        {
            xxx=xx[i];
            yyy=yy[i];
            xx[i]=n-xxx+1;
            yy[i]=m-yyy+1;
        }
    }
    else if(x==3)
    {
        for(i=0;i<p;++i)
        {
            xxx=xx[i];
            yyy=yy[i];
            xx[i]=yyy;
            yy[i]=n-xxx+1;
        }
        swap(n,m);
        for(i=0;i<p;++i)
        {
            xxx=xx[i];
            yyy=yy[i];
            xx[i]=n-xxx+1;
            yy[i]=m-yyy+1;
        }
    }
    if(y==1)
    {
        for(i=0;i<p;++i)
        yy[i]=m-yy[i]+1;
    }
    if(z==1)
    {
        for(i=0;i<p;++i)
        {
            xxx=xx[i];
            yyy=yy[i];
            xx[i]=m-yyy+1;
            yy[i]=xxx;
        }
        swap(n,m);
    }
    else if(z==2)
    {
        for(i=0;i<p;++i)
        {
            xxx=xx[i];
            yyy=yy[i];
            xx[i]=n-xxx+1;
            yy[i]=m-yyy+1;
        }
    }
    else if(z==3)
    {
        for(i=0;i<p;++i)
        {
            xxx=xx[i];
            yyy=yy[i];
            xx[i]=m-yyy+1;
            yy[i]=xxx;
        }
        swap(n,m);
        for(i=0;i<p;++i)
        {
            xxx=xx[i];
            yyy=yy[i];
            xx[i]=n-xxx+1;
            yy[i]=m-yyy+1;
        }
    }
    for(i=0;i<p;++i)
    cout<<xx[i]<<" "<<yy[i]<<endl;
    return 0;
}