#include<iostream>
#include<cstdio>
using namespace std;
#define int long long
int t,hc,dc,hm,dm,n,w,a;
signed main()
{
    cin>>t;
    while(t--)
    {
        cin>>hc>>dc>>hm>>dm>>n>>w>>a;
        hc+=n*a;
        bool flag=0;
        for(int i=n;i>=0;--i)
        {
            if((hm+dc-1)/dc<=(hc+dm-1)/dm)
            {
                flag=1;
                break;
            }
            hc-=a;
            dc+=w;
        }
        cout<<(flag? "YES":"NO")<<'\n';
    }
    return 0;
}