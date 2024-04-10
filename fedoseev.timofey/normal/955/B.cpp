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
    string s;
    cin >> s;
    map <char, int> cnt;
    for (auto c : s) {
        ++cnt[c];
    }
    if (cnt.size() == 1 || cnt.size() > 4) {
        cout << "No" << endl;
        return 0;
    }
    else {
        if (cnt.size() == 4) {
            cout << "Yes" << endl;
            return 0;
        }
        if (cnt.size() == 2) {
            for (auto p : cnt) {
                if (p.second == 1) {
                    cout << "No" << endl;
                    return 0;
                }
            }
            cout << "Yes" << endl;
            return 0;
        }
        if (cnt.size() == 3) {
            for (auto p : cnt) {
                if (p.second != 1) {
                    cout << "Yes" << endl;
                    return 0;
                }
            }
            cout << "NO" << endl;
            return 0;
        }
    }
}