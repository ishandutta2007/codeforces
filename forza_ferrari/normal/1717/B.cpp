#include<iostream>
#include<cstdio>
using namespace std;
int t,n,k,x,y;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>k>>x>>y;
        --x;
        --y;
        int pos=((y%k)-x%k+k)%k;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
                cout<<(j%k==pos? 'X':'.');
            cout<<'\n';
            pos=(pos+1)%k;
        }
    }
    return 0;
}