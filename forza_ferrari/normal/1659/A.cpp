#include<iostream>
#include<cstdio>
using namespace std;
int t,n,a,b;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>a>>b;
        int len=a/(b+1),w=a%(b+1);
        for(int i=1;i<=b+1;++i)
        {
            for(int j=1;j<=len;++j)
                cout<<'R';
            if(i<=w)
                cout<<'R';
            if(i!=b+1)
                cout<<'B';
        }
        cout<<'\n';
    }
    return 0;
}