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
        --a[i];
    }
    vector <int> used(n);
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (used[i]) continue;
        ++cnt;
        int cur = i;
        while (!used[cur]) {
            used[cur] = 1;
            cur = a[cur];
        }
    }
    if (cnt % 2 == 1) {
        cout << "Um_nik\n";
    }
    else {
        cout << "Petr\n";
    }
}