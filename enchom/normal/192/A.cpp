#include <iostream>
using namespace std;
long long precomputed[50000];
int main()
{
    long long i;
    long long n;
    long long uk;
    long long need;
    for (i=1;i<=45000;i++)
    precomputed[i]=( i*(i+1) )/2;
    
    cin>>n;
    uk=45000;
    for (i=1;i<=45000;i++)
    {
        need=n-precomputed[i];
        if (need<=0)
        break;
        
        while (precomputed[uk]>need && uk>=1)
        uk--;
        
        if (uk==0)
        break;
        
        if (precomputed[uk]==need)
        {
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
    return 0;
}