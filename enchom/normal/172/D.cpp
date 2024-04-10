#include <iostream>
using namespace std;

typedef long long Int;

Int check[10000001];
Int months=0;

int main()
{
    Int a,n;
    Int i,j;
    
    cin>>a>>n;
    
    for (i=1;i*i<=10000000;i++)
    {
        for (j=i*i;j<=10000000;j=j+i*i)
        {
            check[j]=i*i;
        }
    }
    for (i=a;i<=a+n-1;i++)
    {
        months=months+(i/check[i]);
    }
    cout<<months<<endl;
    return 0;
}