#include <iostream>
using namespace std;

typedef long long Int;

Int a[100001];

int main()
{
    Int n;
    Int i;
    Int total=0;
    
    cin>>n;
    
    for (i=1;i<=n;i++)
    {
        cin>>a[i];
        
        if (i!=1 && a[i-1]-a[i]>=1)
        total=total+(a[i-1]-a[i]);
    }
    cout<<total<<endl;
    return 0;
}