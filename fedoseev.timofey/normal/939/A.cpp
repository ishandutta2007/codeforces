#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <list>
#include <time.h>
#include <math.h>
#include <random>
#include <deque>
#include <queue>
#include <cassert>
#include <unordered_map>
#include <iomanip>
#include <bitset>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        --x;
        a[i] = x;
    }
    for (int i = 0; i < n; ++i) {
        if (a[a[a[i]]] == i) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
}