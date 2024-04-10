#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

ll n, x, k = 1;

int main()
{
    ios_base::sync_with_stdio(false);
    
    cin >> n;
    while (x + k < n)
        x += k++;
    cout << n - x;

    return 0;
}