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
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector <int> tmp = a;
    sort(tmp.rbegin(), tmp.rend());
    vector <int> res;
    while (!a.empty()) {
        for (int i = 0; i + 1 < a.size(); ++i) {
            bool flag = false;
            if (a[i] > a[i + 1]) flag = true;
            int x = a[i] + a[i + 1];
            if (!flag) {
                a[i] = x / 2;
                a[i + 1] = x - a[i];
            }
            else {
                a[i + 1] = x / 2;
                a[i] = x - a[i + 1];
            }
        }
        int mx = -1;
        for (int i = 0; i < a.size(); ++i) {
            mx = max(mx, a[i]);
        }
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] == mx) {
                res.push_back(a[i]);
                a.erase(a.begin() + i);
                break;
            }
        }
    }
    if (res == tmp) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
}