#include <bits/stdc++.h>
using namespace std;
# define M 1000000007

int modInverse(int a, int m);
int gcd(int a, int b);
int power(int x, unsigned int y, unsigned int m);


int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b%a, a);
}

int power(int x, unsigned int y, unsigned int m)
{
    if (y == 0)
        return 1;
    int p = power(x, y/2, m) % m;
    p = (p * p) % m;

    return (y%2 == 0)? p : (x * p) % m;
}

int modInverse(int a, int m)
{
    int m0 = m;
    int y = 0, x = 1;

    if (m == 1)
      return 0;

    while (a > 1)
    {
        // q is quotient
        int q = a / m;
        int t = m;

        // m is remainder now, process same as
        // Euclid's algo
        m = a % m, a = t;
        t = y;

        // Update y and x
        y = x - q * y;
        x = t;
    }

    // Make x positive
    if (x < 0)
       x += m0;

    return x;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int c1,c2,c3,c4;
    cin>>c1>>c2>>c3>>c4;
    if(c1!=c4) cout<<0;
    else
    {
        if(c3!=0&&c1==0) cout<<0;
        else cout<<1;
    }
    return 0;
}