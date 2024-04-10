#include<bits/stdc++.h>
using namespace std;
int k,n,s,p;

int main()
{
    cin >> k >> n >> s >> p;
    cout << (k*((n-1)/s+1)-1)/p+1 << endl;
}