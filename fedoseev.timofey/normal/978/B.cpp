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
    string s;
    cin >> s;
    vector <int> cnt;
    for (int i = 0; i < n; ++i) {
        if (s[i] != 'x') continue;
        int r = i;
        while (r < n && s[r] == 'x') ++r;
        cnt.push_back(r - i);
        i = r;
    }
    int ans = 0;
    for (int i = 0; i < cnt.size(); ++i) {
        ans += max(0, cnt[i] - 2);
    }
    cout << ans << '\n';
}