#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int a, b, x, y;

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> a >> b;
    while (true) {
        ++x;
        if (x * x > a) {
            --x;
            break;
        }
    }
    while (true) {
        ++y;
        if (y * (y + 1) > b) {
            --y;
            break;
        }
    }
    cout << (x > y ? "Valera" : "Vladik");

    return 0;
}