#include<iostream>
#include<cstdlib>
using namespace std;
int n,c1,c2,c3,x;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        if(x==1)c1++;
        else if(x==2)c2++;
        else if(x==3)c3++;
    }
    cout<<n-max(c1,max(c2,c3));
    return 0;
}