#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int,int> pii;


int main()
{
    ll n;
    cin >> n;
    n = n / 10000 % 10 * 10000 + n / 100 % 10 * 1000 + n / 1 % 10 * 100 + n / 10 % 10 * 10 + n / 1000 % 10 * 1;
    n = ((n * n * n) % 100000 * (n * n) % 100000) % 100000;
    cout << n / 10000 % 10 << n / 1000 % 10 << n / 100 % 10 << n / 10 % 10 << n / 1 % 10 << endl;

    return 0;
}