#include<iostream>
#include<cstdio>
using namespace std;
int t,n,k,sum;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        sum=0;
        for(register int i=n-1;~i;--i)
        {
            cout<<(sum^i)<<endl;
            sum=i;
            int x;
            cin>>x;
            if(x)
                break;
        }
    }
    return 0;
}