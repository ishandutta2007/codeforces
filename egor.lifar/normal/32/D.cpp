#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
#include <map>
#include <set>
#include <cstring>
#include <cmath>


using namespace std;


int n, m, l;
string s[301];


int main() {
    cin >> n >> m >> l;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (s[i][j] != '*') {
                    continue;
                }
                int mx = min(min(i, j), min(n - i - 1, m - j - 1));
                if (mx < k) {
                    continue;
                }
                if (s[i - k][j] == '*' && s[i + k][j] == '*' && s[i][j + k] == '*' && s[i][j - k] == '*') {
                    l--;
                    if (l == 0) {
                        cout << i + 1 << ' ' << j + 1 << endl;
                        cout << i - k + 1 << ' ' << j + 1 << endl;
                        cout << i + k + 1 << ' ' << j + 1 << endl;
                        cout << i + 1 << ' ' << j - k + 1 << endl;
                        cout << i + 1 << ' ' << j + k + 1 << endl;
                    }
                }
            }
        }
    }
    if (l > 0) {
        cout << -1 << endl;
    }
    return 0;
}