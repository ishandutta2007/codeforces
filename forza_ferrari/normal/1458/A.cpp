#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
#define int long long
int n,m,g,lst,fst;
inline int gcd(int x,int y)
{
    if(!x||!y)
        return x|y;
    return x%y? gcd(y,x%y):y;
}
signed main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i)
    {
        int x;
        cin>>x;
        if(!fst)
            fst=x;
        if(lst)
            g=gcd(g,abs(x-lst));
        lst=x;
    }
    for(int i=1;i<=m;++i)
    {
        int x;
        cin>>x;
        cout<<gcd(g,fst+x)<<" ";
    }
    cout<<'\n';
    return 0;
}