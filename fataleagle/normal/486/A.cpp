#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n;
    cin>>n;
    if(n&1)
        cout<<-n/2-1<<endl;
    else
        cout<<n/2<<endl;
    return 0;
}