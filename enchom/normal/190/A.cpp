#include <iostream>
using namespace std;

int MAX(int a,int b)
{
    if (a>b)
    return a;
    else
    return b;
}

int main()
{
    int n,m;
    int min,max;
    
    cin>>n>>m;
    if (n==0 && m==0)
    {
        cout<<0<<" "<<0<<endl;
        return 0;
    }
    if (n==0)
    {
        cout<<"Impossible"<<endl;
        return 0;
    }
    if (n>=m)
    min=n;
    else
    min=m;
    
    if (m>0)
    max=n+m-1;
    else
    max=n+m;
    
    cout<<min<<" "<<max<<endl;
    return 0;
}