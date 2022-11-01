#include <bits/stdc++.h>
using namespace std;

#define REP(i, a, b) for(int i = a; i < b; i++)

const int maxn = 100100;
const int inf = 1e9 + 100;

int a, b, c, d;

int main()
{
    cin >> a >> b >> c >> d;
    cout << 2 * a + 2 * b + 4 + 2 * c + 2 * d + 4 - c - c - 2 - 2;
    return 0;
}