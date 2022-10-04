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
    int n, k;
    cin >> n >> k;
    set <string> a;
    string good(k, '0');
    int cgood = 0;
    for (int i = 0; i < n; ++i) {
        string s;
        for (int j = 0; j < k; ++j) {
            char c;
            cin >> c;
            s.push_back(c);
        }
        a.insert(s);
        if (s == good) ++cgood;
    }
    if (cgood >= 2) {
        cout << "YES\n";
        return 0;
    }
    if (n == 1 && cgood == 1) {
        cout << "YES\n";
        return 0;
    }
    else if (n == 1) {
        cout << "NO\n";
        return 0;
    }
    for (auto &s : a) {
        for (auto &t : a) {
            if (s == t) continue;
            bool bad = 0;
            for (int i = 0; i < k; ++i) {
                if (s[i] == '1' && t[i] == '1') {
                    bad = 1;
                    break;
                } 
            }
            if (!bad) {
                cout << "YES\n";
                return 0;
            }
        }
    }
    cout << "NO\n";
}