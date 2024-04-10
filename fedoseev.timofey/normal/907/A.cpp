#include <iostream>
#include <vector>

using namespace std;

int main() {
    int v1, v2, v3, v4;
    cin >> v1 >> v2 >> v3 >> v4;
    for (int i = 1; i <= 200; ++i) {
        for (int j = 1; j <= 200; ++j) {
            for (int k = 1; k <= 200; ++k) {
                if (v1 > i || v2 > j || v3 > k) continue;
                if (2 * v1 < i || 2 * v2 < j || 2 * v3 < k) continue;
                if (v4 > i || v4 > j || v4 > k) continue;
                if (2 * v4 >= i || 2 * v4 >= j) continue;
                if (2 * v4 < k) continue;
                if (!(i > j && j > k)) continue;
                cout << i << endl << j << endl << k << endl;
                return 0;
            }
        }
    }
    cout << -1 << endl;
}