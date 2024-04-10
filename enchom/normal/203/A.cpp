#include <iostream>
using namespace std;
int main()
{
    int x,t,a,da,b,db;
    int task1,task2;
    int i,j;
    cin>>x>>t>>a>>b>>da>>db;
    for (i=0;i<=t-1;i++)
    {
        for (j=0;j<=t-1;j++)
        {
            task1=a-da*i;
            task2=b-db*j;
            
            if (task1<0)
            task1=0;
            if (task2<0)
            task2=0;
            
            if ( task1+task2==x || task1==x || task2==x || x==0)
            {
                cout<<"YES"<<endl;
                return 0;
            }
        }
    }
    cout<<"NO"<<endl;
    return 0;
}