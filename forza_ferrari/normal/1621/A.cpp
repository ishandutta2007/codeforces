#include<iostream>
#include<cstdio>
using namespace std;
int t,n,m;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        if(m>(n+1)/2)
        {
            cout<<"-1\n";
            continue;
        }
        for(int i=1;i<=n;++i,cout<<'\n')
            for(int j=1;j<=n;++j)
                if(i==j&&(i&1)&&m)
                {
                    --m;
                    cout<<'R';
                }
                else
                    cout<<'.';
    }
    return 0;
}