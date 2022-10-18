#include<iostream>
#include<cstdio>
using namespace std;
int t,n,l,r,u,d;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>u>>r>>d>>l;
        if(u>n||r>n||d>n||l>n)
        {
            puts("NO");
            continue;
        }
        if(n==1)
        {
            if(l==r&&u==d&&l==u)
                puts("YES");
            else
                puts("NO");
            continue;
        }
        bool flag=0;
        for(int s=0;s<16;++s)
        {
            if(s&1)
                --l,--u;
            if(s>>1&1)
                --l,--d;
            if(s>>2&1)
                --r,--u;
            if(s>>3&1)
                --r,--d;
            if(l>=0&&l<=n-2&&r>=0&&r<=n-2&&u>=0&&u<=n-2&&d>=0&&d<=n-2)
            {
                flag=1;
                break;
            }
            if(s&1)
                ++l,++u;
            if(s>>1&1)
                ++l,++d;
            if(s>>2&1)
                ++r,++u;
            if(s>>3&1)
                ++r,++d;
        }
        puts(flag? "YES":"NO");
    }
    return 0;
}