#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

char s[7][7];

int main()
{
    ios_base::sync_with_stdio(false);

    for (int i = 1; i <= 4; ++i)
        cin >> s[i] + 1;
    for (int i = 1; i <= 4; ++i) {
        for (int j = 1; j <= 4; ++j) {
            if (s[i][j] == 'o') continue;
            if (s[i][j] == 'x') {
                if (s[i][j - 1] == 'x' && s[i][j + 1] == '.' ||
                    s[i][j - 1] == '.' && s[i][j + 1] == 'x' ||
                    s[i - 1][j - 1] == 'x' && s[i + 1][j + 1] == '.' ||
                    s[i - 1][j - 1] == '.' && s[i + 1][j + 1] == 'x' ||
                    s[i - 1][j] == 'x' && s[i + 1][j] == '.' ||
                    s[i - 1][j] == '.' && s[i + 1][j] == 'x' ||
                    s[i - 1][j + 1] == 'x' && s[i + 1][j - 1] == '.' ||
                    s[i - 1][j + 1] == '.' && s[i + 1][j - 1] == 'x') {
                    cout << "YES\n";
                    return 0;
                }
            }
            if (s[i][j] == '.') {
                if (s[i][j - 1] == 'x' && s[i][j + 1] == 'x' ||
                    s[i - 1][j - 1] == 'x' && s[i + 1][j + 1] == 'x' ||
                    s[i - 1][j] == 'x' && s[i + 1][j] == 'x' ||
                    s[i - 1][j + 1] == 'x' && s[i + 1][j - 1] == 'x') {
                    cout << "YES\n";
                    return 0;
                }
            }
        }
    }
    cout << "NO\n";

    return 0;
}