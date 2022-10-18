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
    cout << n - (n / 2 + n / 3 + n / 5 + n / 7 - n / 2 / 3 - n / 2 / 5 - n / 2 / 7 - n / 3 / 5 - n / 3 / 7 - n / 5 / 7
             + n / 2 / 3 / 5 + n / 2 / 3 / 7 + n / 2 / 5 / 7 + n / 3 / 5 / 7 - n / 2 / 3 / 5 / 7);
    return 0;
}