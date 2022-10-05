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
    vector <int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    string b;
    cin >> b;
    int l = -1e9, r = 1e9;
    for (int i = 4; i < n; ++i) {
        if (b[i] != b[i - 1]) {
            if (b[i] == '1') {
                for (int j = i - 4; j <= i; ++j) {
                    l = max(l, a[j] + 1);
                }
            }
            else {
                for (int j = i - 4; j <= i; ++j) {
                    r = min(r, a[j] - 1);
                }
            }
        }
    }
    r = max(r, l);
    cout << l << " " << r << endl;
}