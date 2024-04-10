#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int n,i;
long double mx[100005],mn[100005],p[100005],g[100005],a=0,b=0,sum,d;
int main()
{
    io
    cin>>n;
    for(i=1;i<=n;++i)
    cin>>mx[i];
    for(i=1;i<=n;++i)
    cin>>mn[i];
    cout<<fixed<<setprecision(20);
    for(i=1;i<n;++i)
    {
        sum=mx[i]+mn[i];
        d=(a-b-sum)*(a-b-sum)-4*(mx[i]-a*sum);
        d=sqrt(d);
        if(d>1e-8)
        {
            if(abs((a-b-sum)-d)>1e-8)
            g[i]=(d-a+b+sum)/2.0;
            else g[i]=0;
        }
        else
        {
            if(abs(a-b-sum)>1e-8)
            g[i]=(sum+b-a)/2.0;
            else g[i]=0;
        }
        p[i]=sum-g[i];
        a+=g[i];
        b+=p[i];
    }
    p[n]=1.0-b;
    g[n]=1.0-a;
    for(i=1;i<=n;++i)
    cout<<p[i]<<" ";
    cout<<endl;
    for(i=1;i<=n;++i)
    cout<<g[i]<<" ";
    cout<<endl;
    return 0;
}