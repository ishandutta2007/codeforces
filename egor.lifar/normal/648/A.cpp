#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
#include <unordered_map>
#include <set>


using namespace std;


int n, m;
string s[101];
int cnt[101];


int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '*') {
                cnt[j]++;
            }
        }
    }
    int ans = 0;
    int ans1 = 0;
    for (int j = 0; j < m - 1; j++) {
        ans = max(ans, cnt[j + 1] - cnt[j]);
    }
    for (int j = 1; j < m; j++) {
        ans1 = max(ans1, cnt[j - 1] - cnt[j]);
    }
    cout << ans << ' ' << ans1 << endl;
    return 0;
}