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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    vector <int> have(1e6 + 7);
    int ans = 0;
    int cur = 0;
    for (int i = 0; i < n; ++i) {
        char c;
        int x;
        cin >> c >> x;
        if (c == '+') {
            have[x] = 1;
            ++cur;
            ans = max(ans, cur);
        }
        else {
            if (have[x]) {
                have[x] = 0;
                --cur;
            }
            else ++ans;
        }
    }
    ans = max(ans, cur);
    cout << ans << '\n';
}