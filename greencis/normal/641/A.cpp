#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, d[200105], u[200105];
char s[200105];
int x = 0;

int main()
{
    cin >> n >> s;
    for (int i = 0; i < n; ++i) {
        cin >> d[i];
    }

    while (x >= 0 && x <= n - 1) {
        if (u[x]) { cout << "INFINITE"; return 0; }
        u[x] = 1;
        if (s[x] == '>')
            x += d[x];
        else
            x -= d[x];
    }
    cout << "FINITE";

    return 0;
}