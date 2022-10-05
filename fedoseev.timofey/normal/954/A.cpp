#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <ctime>
#include <random>
#include <cmath>
#include <bitset>
#include <iomanip>
#include <list>

using namespace std;

typedef long long ll;
const int N = 107;

bool used[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 0; i + 1 < n; ++i) {
        if (s[i] == 'U' && s[i + 1] == 'R') {
            used[i] = 1;
            used[i + 1] = 1;
            ++ans;
            ++i;
        }
        else if (s[i] == 'R' && s[i + 1] == 'U') {
            used[i] = 1;
            used[i + 1] = 1;
            ++ans;
            ++i;
        }
        else {
            ++ans;
            used[i] = 1;
        }
    }
    if (!used[n - 1]) ++ans;
    cout << ans << endl;
}