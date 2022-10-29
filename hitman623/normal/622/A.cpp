#include <iostream>

using namespace std;

int main()
{
    long long n,i;
    cin>>n;
    for(i=1;i<n;++i)
    {
      if((i*(i+1))/2>=n) break;
    }
    cout<<n-(i*(i-1))/2;
    return 0;
}