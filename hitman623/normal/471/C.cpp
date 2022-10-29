#include <bits/stdc++.h>
#define pb push_back
#define long long long
#define pll pair < long , long >
#define vll vector < pll >
#define vl vector < long >
#define io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int main()
{
    io
    long n,i,c=0;
    cin>>n;
    for(i=1;i*i<n;++i)
    {
        if((n+i)%3==0 && (n+i)/3>=(i*(i+1))/2)
        c++;
    }
    cout<<c;
    return 0;
}