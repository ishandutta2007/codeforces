#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <tuple>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector <vector <int>> v(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 6; ++j) {
            int x;
            cin >> x;
            v[i].push_back(x);
        }
    }
    set <int> x;
    if (n == 1) for (auto e : v[0]) x.insert(e);
    else if (n == 2) {
        for (auto e : v[0]) x.insert(e);
        for (auto e : v[1]) x.insert(e);
        for (auto i : v[0]) {
            for (auto j : v[1]) {
                x.insert(10 * i + j);
                x.insert(10 * j + i);
            }
        }
    }
    else {
        for (auto e : v[0]) x.insert(e);
        for (auto e : v[1]) x.insert(e);
        for (auto e : v[2]) x.insert(e);
        for (auto i : v[0]) {
            for (auto j : v[1]) {
                for (auto k : v[2]) {
                    x.insert(i * 10 + j);
                    x.insert(i * 10 + k);
                    x.insert(j * 10 + i);
                    x.insert(j * 10 + k);
                    x.insert(k * 10 + i);
                    x.insert(k * 10 + j);
                    x.insert(100 * i + 10 * j + k);
                    x.insert(100 * i + 10 * k + j);
                    x.insert(100 * j + 10 * i + k);
                    x.insert(100 * j + 10 * k + i);
                    x.insert(100 * k + 10 * i + j);
                    x.insert(100 * k + 10 * j + i);
                }
            }
        }
    }
    int cur = 0;
    for (auto elem : x) {
        if (elem == 0) continue;
        if (elem == cur + 1) ++cur;
        else break;
    }
    cout << cur << endl;
}