#include <iostream>
#define ll long long
using namespace std;

ll gcd(ll a, ll b) {
    return b ? gcd(b,a%b) : a;
}

ll x,y,a,b;

int main()
{
    cin>>x>>y>>a>>b;
    cout<< (b / (x*y/gcd(x,y))) - ((a-1) / (x*y/gcd(x,y)));

    return 0;
}