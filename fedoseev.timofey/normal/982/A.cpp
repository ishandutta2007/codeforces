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
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            if (i) {
                if (s[i - 1] != '0') {
                    cout << "No\n";
                    return 0;
                }
            }
            if (i != n - 1) {
                if (s[i + 1] != '0') {
                    cout << "No\n";
                    return 0;
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (s[i] != '0') continue;
        if (i && s[i - 1] != '0') continue;
        if (i != n - 1 && s[i + 1] != '0') continue;
        cout << "No\n";
        return 0;
    }
    cout << "Yes\n";
    return 0;
}