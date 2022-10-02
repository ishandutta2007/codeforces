#include <cstdio>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <set>

using namespace std;



long long l, r;



long long nod(long long a, long long b) {
    if (a == 0LL) {
        return b;
    }
    return nod(b % a, a);
}




int main() {
    cin >> l >> r;
    for (long long i = l; i <= r; i++) {
        for (long long j = l; j <= r; j++) {
            for (long long k = l; k <= r; k++) {
                if (nod(i, j) == 1 && nod(j, k) == 1 && i != j && j != k && i != k) {
                    if (nod(i, k) != 1 && i < j && j < k) {
                        cout << i << ' ' << j << ' ' << k << endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout << -1 << endl;
    return 0;
}