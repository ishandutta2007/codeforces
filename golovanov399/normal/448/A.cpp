#include <iostream>
#include <vector>
#include <algorithm>

#define x first
#define y second
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

int main()
{
    int a, b, n, x;
    a = b = 0;
    cin >> x;
    a += x;
    cin >> x;
    a += x;
    cin >> x;
    a += x;
    cin >> x;
    b += x;
    cin >> x;
    b += x;
    cin >> x;
    b += x;
    cin >> n;
    if ((a + 4) / 5 + (b + 9) / 10 > n) cout << "NO\n"; else cout << "YES\n";

    return 0;
}