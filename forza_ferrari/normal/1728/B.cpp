#include<iostream>
#include<cstdio>
using namespace std;
int t,n;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;

        if(n&1)
        {
            for(int i=n-2;i>=4;--i)
                cout<<i<<" ";
            cout<<"1 2 3\n";
        }
        else
            for(int i=n-2;i>=1;--i)
                cout<<i<<" ";
        cout<<n-1<<" "<<n<<'\n';
    }
    return 0;
}