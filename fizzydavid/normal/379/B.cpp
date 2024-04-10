#include<iostream>
using namespace std;
int i,n,a[301];
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
    cin>>a[i];
    for(i=1;i<n;i++)
    {
        if(a[i]>0)
        {
            cout <<"P";
            a[i]-=1;
            while(a[i]>0)
            {
                cout<<"RLP";
                a[i]-=1;
            }
        }
        cout<<"R";
    }
    if(a[n]>0)
    {
        cout<<"P";
        a[n]-=1;
        while(a[n]>0)
        {
            cout<<"LRP";
            a[n]-=1;
        }
    }
    return 0;
}