#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int main(void)
{
    int n;
    int i;

    cin >> n;
    for(int i=2;i<=n;i++)for(;!(n%i);n/=i)cout<<i;
        cout<<endl;

    return 0;
}