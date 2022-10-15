#include <iostream>

using namespace std;
//               0, 1, 2, 3, 4, 5, 6, 7, 8, 9, A, B, C, D, E, F 
int holes[16] = {1, 0, 0, 0, 1, 0, 1, 0, 2, 1, 1, 2, 0, 1, 0, 0};

int main() {
    int n; cin >> n;
    if (n == 0) {
        cout << 1 << endl;
        return 0;
    }
    int res = 0;
    while (n) {
        res += holes[n & 15];
        n >>= 4;
    }
    cout << res << endl;
    return 0;
}