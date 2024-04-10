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
    int b = 1, e = n;
    for (int i = 0; i + 1 < k; ++i) {
        if (i % 2 == 0) {
            cout << b++ << ' ';
        }
        else cout << e-- << ' ';
    }
    if (k % 2 == 1) {
        for (int i = b; i <= e; ++i) {
            cout << i << ' ';
        }
    }
    else {
        for (int i = e; i >= b; --i) {
            cout << i << ' ';
        }
    }
}