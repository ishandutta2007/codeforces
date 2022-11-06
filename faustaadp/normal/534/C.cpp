#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,hz,d,i,a[10101010],a2[10101010],hs,m,m1,m2;
int main()
{
    cin>>n>>m;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
        hz=hz+a[i];
    }
    for(i=1;i<=n;i++)
    {
        m1=m-(hz-a[i]);
        m2=m-(n-1);
        m1=max(m1,1LL);
        m2=min(m2,a[i]);
       // cout<<m1<<" s "<<m2<<"\n";
        if(i!=n)
            cout<<a[i]-(m2-m1+1)<<" ";
        else
            cout<<a[i]-(m2-m1+1)<<"\n";
    }

}