#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <iomanip>

using namespace std;

int s(int x) {
    int res = 0;
    while (x > 0) {
        res += x % 10;
        x /= 10;
    }
    return res;
}

int main() {
    int k;
    cin >> k;
    int cur = 0;
    int cnt = 0;
    while (cnt < k) {
        ++cur;
        if (s(cur) == 10) ++cnt;
    }
    cout << cur << endl;
}