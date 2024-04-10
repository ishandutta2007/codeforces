#include<iostream>
#include<cstdio>
using namespace std;
long long n,m,p,a[100001],ans;
int main()
{
    cin>>n>>m>>p;
    for(int i=1;i<=m;++i)
        cin>>a[i];
    long long l=1,r=p,pos=1,tmp;
    while(pos<=m)
    {
        tmp=r;
        while(pos<=m&&a[pos]<=r)
        {
            ++pos;
            ++tmp;
        }
        if(pos<=m&&r==tmp)
        {
            l=r+1;
            l+=(a[pos]-l)/p*p;
            r=l+p-1;
        }
        else
        {
            ++ans;
            r=tmp;
        }
    }
    cout<<ans<<'\n';
    return 0;
}