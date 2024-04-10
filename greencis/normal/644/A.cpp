#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int v[105][105];

int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    if (n / 2 <= (a * b + 1) / 2 && (n + 1) / 2 <= a * b / 2) {
        int y = 0, x = 0;
        for (int i = 2; i <= n; i += 2) {
            v[y][x] = i;
            if (b == 1) y += 2;
            else {
                x += 2;
                if (x >= b)
                    ++y, x = y % 2;
            }
        }
        y = 0, x = 1;
        if (b == 1) y = 1, x = 0;
        for (int i = 1; i <= n; i += 2) {
            v[y][x] = i;
            if (b == 1) y += 2;
            else {
                x += 2;
                if (x >= b)
                    ++y, x = 1 - y % 2;
            }
        }
    } else if (n / 2 <= a * b / 2 && (n + 1) / 2 <= (a * b + 1) / 2) {
        int y = 0, x = 0;
        for (int i = 1; i <= n; i += 2) {
            v[y][x] = i;
            if (b == 1) y += 2;
            else {
                x += 2;
                if (x >= b)
                    ++y, x = y % 2;
            }
        }
        y = 0, x = 1;
        if (b == 1) y = 1, x = 0;
        for (int i = 2; i <= n; i += 2) {
            v[y][x] = i;
            if (b == 1) y += 2;
            else {
                x += 2;
                if (x >= b)
                    ++y, x = 1 - y % 2;
            }
        }
    } else {
        cout << "-1";
        return 0;
    }
    for (int i = 0; i < a; ++i) {
        for (int j = 0; j < b; ++j)
            cout << v[i][j] << " ";
        cout << "\n";
    }
    return 0;
}