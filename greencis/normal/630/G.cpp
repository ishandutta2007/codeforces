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
    cout << (n + 4) * (n + 3) * (n + 2) * (n + 1) * n / 120 * ((n + 2) * (n + 1) * n / 6);

    return 0;
}