#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    int ones = 0, twos = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (x == 1) ++ones;
        if (x == 2) ++twos;
    }
    cout << min(ones, twos) + (ones - min(ones, twos)) / 3 << endl;
}