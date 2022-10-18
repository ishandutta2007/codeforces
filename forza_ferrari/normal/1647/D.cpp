#include<iostream>
#include<cstdio>
using namespace std;
#define int long long
int t,n,d;
inline bool prime(int x)
{
    if(x==1)
        return 1;
    for(int i=2;i*i<=x;++i)
        if(x%i==0)
            return 0;
    return 1;
}
signed main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>d;
        int tmp=0;
        while(n%d==0)
        {
            ++tmp;
            n/=d;
        }
        if(tmp<2)
        {
            puts("NO");
            continue;
        }
        if(!prime(n))
        {
            puts("YES");
            continue;
        }
        if(tmp==2)
        {
            puts("NO");
            continue;
        }
        if(tmp==3)
        {
            if(n==1)
            {
                puts(prime(d)? "NO":"YES");
                continue;
            }
            if(prime(d))
            {
                puts("NO");
                continue;
            }
            puts(1ll*n*n==d? "NO":"YES");
            continue;
        }
        puts(prime(d)? "NO":"YES");
    }
    return 0;
}