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
    int tmp = n;
    if (n <= 5) {
        cout << -1 << "\n";
    }
    else {
        if (n % 2 == 0) {
            n -= 3;
            for (int i = 1; i < n; ++i) {
                cout << i << " " << i + 1 << "\n";
            }
            cout << n - 1 << " " << n + 1 << "\n";
            cout << n + 1 << " " << n + 2 << "\n";
            cout << n + 1 << " " << n + 3 << "\n";
        }
        else {
            n -= 4;
            for (int i = 1; i < n; ++i) {
                cout << i << " " << i + 1 << "\n";
            }
            cout << n - 1 << " " << n + 1 << "\n";
            cout << n - 1 << " " << n + 2 << "\n";
            cout << n + 1 << " " << n + 3 << "\n";
            cout << n + 1 << " " << n + 4 << "\n";
        }
    }
    n = tmp;
    for (int i = 1; i < n; ++i) {
        cout << i << " " << i + 1 << "\n";
    }
}