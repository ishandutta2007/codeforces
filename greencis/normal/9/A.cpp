#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

int n,m;
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main()
{
    cin >> n >> m;
    n = max(n,m);
    int a = 7 - n;
    int b = 6;
    int g = gcd(a,b);
    a/=g;b/=g;
    cout << a<< "/"<<b;

    return 0;
}