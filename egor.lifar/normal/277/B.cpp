#include <iostream>
#include <fstream>
#include <cassert>
#include <cstdlib>
#include <cmath>
#include <map>
#include <set>
#include <algorithm>
#include <vector>
#include <queue>
#include <list>
#include <cstring>
#include <unordered_map>


using namespace std;



int n, m;


int main() {
    cin >> n >> m;
    if (m == 3) {
        if (n == 3) {
            cout << 0 << ' ' << 0 << endl;
            cout << 0 << ' ' << 1 << endl;
            cout << 1 << ' ' << 0 << endl;
            return 0;
        }
        if (n == 4) {
            cout << 0 << ' ' << 0 << endl;
            cout << 0 << ' ' << 10 << endl;
            cout << 10 << ' ' << 0 << endl;
            cout << 1 << ' ' << 1 << endl;
            return 0;
        }
        cout << -1 << endl;
        return 0;
    }
    int x = 10000000;
    for (int i = 0; i < m; i++) {
        cout << i << ' ' << x + i * i << endl;
    }
    for (int i = 0; i < n - m; i++) {
        cout << i << ' ' << -x - i * i << endl;
    }
    return 0;
}