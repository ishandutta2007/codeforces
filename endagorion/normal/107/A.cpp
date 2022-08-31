#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector< int > next(n, -1);
    vector< int > weight(n, -1);
    vector< bool > in(n, false);
    for (int i = 0; i < m; ++i) {
        int x, y, w;
        cin >> x >> y >> w;
        --x; --y;
        next[x] = y;
        weight[x] = w;
        in[y] = true;
    }

    int q = 0;
    for (int i = 0; i < n; ++i) {
        if (!in[i] && next[i] >= 0) {
            ++q;
        }
    }

    cout << q << '\n';
    for (int i = 0; i < n; ++i) {
        if (!in[i] && next[i] >= 0) {
            int j = i;
            int w = 1000001;
            while (next[j] >= 0) {
                w = min(w, weight[j]);
                j = next[j];
            }
            cout << i + 1 << ' ' << j + 1 << ' ' << w << '\n';
        }
    }
    return 0;
}