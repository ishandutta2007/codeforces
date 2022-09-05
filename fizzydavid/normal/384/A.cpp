#include<cstdlib>
#include<iostream>
using namespace std;
int n;
int main()
{
    int i,j;
    cin>>n;
    cout<<(n*n+1)/2<<endl;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(i%2==j%2)cout<<"C";
            else cout<<".";
        }
        cout<<endl;
    }
    return 0;
}