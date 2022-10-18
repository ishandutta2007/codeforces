#include<iostream>
#include<cstdio>
using namespace std;
int t,n,sum;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        sum=0;
        for(int i=1;i<=n;++i)
        {
            int x;
            cin>>x;
            sum+=x;
        }
        cout<<(sum%n==0? 0:1)<<endl;
    }
    return 0;
}