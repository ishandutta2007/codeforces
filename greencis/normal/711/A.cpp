#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n;
char s[10000][99];

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> s[i];
    int g = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i][0] == 'O' && s[i][1] == 'O') {
            g = 1;
            s[i][0] = '+';
            s[i][1] = '+';
            break;
        }
        if (s[i][3] == 'O' && s[i][4] == 'O') {
            g = 1;
            s[i][3] = '+';
            s[i][4] = '+';
            break;
        }
    }

    if (!g) cout << "NO";
    else {
        cout << "YES" << endl;
        for (int i = 0; i < n; ++i) cout << s[i] << endl;
    }

    return 0;
}