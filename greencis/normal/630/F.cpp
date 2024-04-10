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
    cout << ull(n * n - 4 * n + 37) * ull(n * (n - 1) * (n - 2) * (n - 3) * (n - 4) / 2 / 3 / 4 / 5) / 6 / 7;
    return 0;
}