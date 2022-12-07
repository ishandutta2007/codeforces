#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
#define pb push_back
#define mp make_pair

int n;

int main()
{
    cin >> n;
    if (n % 2 == 1) {
        cout << n / 2 << endl;
        return 0;
    }
    LL x = 1;
    while (x * 2 <= n) x *= 2;
    n -= x;
    cout << n / 2 << endl;
    return 0;
}