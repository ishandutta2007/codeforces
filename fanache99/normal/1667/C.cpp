#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cassert>
#include <map>
#include <numeric>
#include <cstring>
#include <set>
#include <ctime>
#include <queue>
#include <cmath>
#include <iomanip>
#include <iterator>
#include <bitset>
#include <unordered_map>
#include <complex>
#include <unordered_set>
#include <chrono>
#include <random>

using namespace std;
using namespace std::chrono;



int main() {
    // ifstream cin("input.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    auto startTime = high_resolution_clock::now();
    srand(time(0));

//    for (int n = 1; n <= 1000; n++) {
    int n;
    cin >> n;
    int x = 1;
    while (x < 2 * (n - x) - 1) {
        x++;
    }
    cout << x << "\n";
//    unordered_set<int> ds, is, js;
    if (x % 2 == 1) {
        int i = 0, j = 0;
        for (int s = 1; s <= x; s++) {
//            ds.insert(j - i);
//            is.insert(i);
//            js.insert(j);
            cout << i + 1 << " " << j + 1 << "\n";
            i = (i + 1) % x;
            j = (j + 2) % x;
        }
    } else {
        int i = 0, j = 0;
        for (int s = 1; s <= x / 2; s++) {
//            ds.insert(j - i);
//            is.insert(i);
//            js.insert(j);
            cout << i + 1 << " " << j + 1 << "\n";
            i = (i + 1) % x;
            j = (j + 2) % x;
        }
        j = (j + 1) % x;
        for (int s = 1; s <= x / 2; s++) {
//            ds.insert(j - i);
//            is.insert(i);
//            js.insert(j);
            cout << i + 1 << " " << j + 1 << "\n";
            i = (i + 1) % x;
            j = (j + 2) % x;
        }
    }

//    for (int i = 0; i < x; i++) {
//        assert(is.find(i) != is.end() && js.find(i) != js.end());
//    }
//    for (int d = -(n - x) + 1; d <= (n - x) - 1; d++) {
//        assert(ds.find(d) != ds.end());
//    }
//    }

    auto stopTime = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stopTime - startTime);
//    cout << duration.count() << "\n";
    return 0;
}