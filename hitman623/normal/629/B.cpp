#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
struct s
{
    char g;
    long s,e;
};
int main()
{
    long n,i,j,c,ans=0,day=0,m=0,f=0;
    struct s a[5005];
    cin>>n;
    for(i=0;i<n;++i)
    cin>>a[i].g>>a[i].s>>a[i].e;
    for(day=1;day<=366;++day)
    {
        m=0;f=0;
        for(i=0;i<n;++i)
        if(a[i].s<=day && a[i].e>=day)
        {
            if(a[i].g=='M') m++;
            else f++;
        }
        ans=max(ans,2*(min(m,f)));
    }
    cout<<ans;
    return 0;
}