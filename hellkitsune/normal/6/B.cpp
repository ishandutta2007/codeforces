#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); e++)
typedef long long LL;
typedef pair<int, int> PII;

string s[105];
int n, m;
string tmp;
char z;
bool nei[26] = {};

int main() {
    cin >> n >> m >> tmp;
    z = tmp[0];
    s[0].resize(m + 2, '.');
    s[n + 1].resize(m + 2, '.');
    for (int i = 1; i <= n; ++i) {
        cin >> s[i];
        s[i] = "." + s[i] + ".";
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (s[i][j] == z) {
                if (s[i - 1][j] != '.') nei[s[i - 1][j] - 'A'] = true;
                if (s[i + 1][j] != '.') nei[s[i + 1][j] - 'A'] = true;
                if (s[i][j - 1] != '.') nei[s[i][j - 1] - 'A'] = true;
                if (s[i][j + 1] != '.') nei[s[i][j + 1] - 'A'] = true;
            }
    int ans = 0;
    for (int i = 0; i < 26; ++i)
        if (nei[i] && i != z - 'A')
            ++ans;
    cout << ans << endl;
    return 0;
}