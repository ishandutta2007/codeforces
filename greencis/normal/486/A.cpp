#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int main()
{
 ll n;
 cin >> n;
 if (n % 2ll) cout << -n/2ll-1ll;
 else cout << n/2ll;
 return 0;
}