#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

vector <int> div(int v) {
    vector <int> d;
    for (int i = 1; i <= v; ++i) {
        if (v % i == 0) d.push_back(i);
    }
    return d;
}

int main() {
    int n;
    cin >> n;
    auto d = div(n);
    int last = 1;
    for (int i = 0; i < d.size(); ++i) {
        int l = 0;
        int r = 17;
        while (r - l > 1) {
            int m = (l + r) >> 1;
            if (((1LL << m) - 1) * (1LL << (m - 1)) > d[i]) r = m;
            else l = m;
        }
        if (((1LL << l) - 1) * (1LL << (l - 1)) == d[i]) last = d[i];
    }
    cout << last << endl;
}