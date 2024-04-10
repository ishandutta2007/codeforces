#include<iostream>
#include<cstdio>
using namespace std;
#define int long long
int t,n,minn,node;
signed main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        minn=1e9+7,node=0;
        for(int i=1;i<=n;++i)
        {
            int w;
            cin>>w;
            if(w<minn)
            {
                minn=w;
                node=i;
            }
        }
        if(n&1)
            cout<<"Mike\n";
        else
            cout<<(node&1? "Joe":"Mike")<<'\n';
    }
    return 0;
}