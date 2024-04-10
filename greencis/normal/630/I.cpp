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
    ll q = 1;
    for (int i = 0; i < n - 3; ++i) q *= 4;
    cout << 2 * 3 * 4 * q + (n - 3) * 3 * 3 * q;

    return 0;
}