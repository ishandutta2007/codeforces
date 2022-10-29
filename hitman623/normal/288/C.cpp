#include <bits/stdc++.h>
#define pb push_back
#define long long long
#define pll pair < long , long >
#define vll vector < pll >
#define vl vector < long >
using namespace std;
long n,v[4000005]={0},ans=0,a[1000006],l=1,p[30],m,i,d,x;
long neg(long a)
{
    long x=0,i,as=0;
    while(x<l)
    {
        if(a%2==0) as+=p[x];
        a/=2,x++;
    }
    return as;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    p[0]=1;
    for(i=1;i<30;++i)
    p[i]=2*p[i-1];
    m=n;
    while(m>0)
    l++,m/=2;
    for(i=n;i>=0;i--)
    {
        d=neg(i);
        x=l-1;
        while(v[d]==1 || d>n)
        {
            d-=p[x];
            x--;
        }
        a[i]=d;
        v[d]=1;
        ans+=(i^d);
    }
    cout<<ans<<endl;
    for(i=0;i<=n;++i)
    cout<<a[i]<<" ";
    return 0;
}