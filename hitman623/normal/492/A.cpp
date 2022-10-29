#include <bits/stdc++.h>
#define pb push_back
#define long long long
#define pair < long , long > pll
using namespace std;

int main()
{
    long n,i;
    cin>>n;
    for(i=1;;i++)
    {
        if(n>=(i*(i+1))/2)
            n-=(i*(i+1))/2;
        else break;
    }
    cout<<i-1;
    return 0;
}