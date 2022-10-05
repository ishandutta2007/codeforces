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
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef long long ll;

int cnt[3];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    string s;
    cin >> s;
    int n = s.size();
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'a' && (cnt[1] || cnt[2])) {
            cout << "NO\n";
            return 0;
        }
        if (s[i] == 'b' && cnt[2]) {
            cout << "NO\n";
            return 0;
        }
        ++cnt[s[i] - 'a'];
    }
    if (!cnt[0] || !cnt[1]) {
        cout << "NO\n"; 
        return 0;
    }
    if (cnt[2] != cnt[0] && cnt[2] != cnt[1]) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
}