#include <bits/stdc++.h>

using namespace std;

int main()
{
    cout<<setprecision(30);
    long n;
    cin>>n;
    if(n>12) cout<<pow(2,n)-100*pow(2,n-13);
    else cout<<pow(2,n);
    return 0;
}