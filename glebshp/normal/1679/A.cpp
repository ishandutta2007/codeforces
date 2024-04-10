#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
 
using namespace std;
 
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    uint32_t tc;
    cin >> tc;
    for (size_t tnum = 0; tnum < tc; tnum++) {
        long long n;
        cin >> n;
        if (n == 4) {
            cout << "1 1" << endl;
            continue;
        }
        if (n == 6) {
            cout << "1 1" << endl;
            continue;
        }
        if (n < 8) {
            cout << -1 << endl;
            continue;
        }
        if (n == 8) {
            cout << "2 2" << endl;
            continue;
        }
        if (n % 2 == 1) {
            cout << -1 << endl;
            continue;
        }
        cout << n / 6 + (n % 6 > 0) << ' ' << n / 4 << endl;
    }

    return 0;
}