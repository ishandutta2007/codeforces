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

int result(int x, vector< vector< int > > &sons) {
    int res = 0;
    for (size_t i = 0; i < sons[x].size(); ++i) {
        res = max(res, result(sons[x][i], sons));
    }

    return res + 1;
}

int main() {
    int n;
    cin >> n;
    vector< vector< int > > sons(n + 1);
    for (int i = 1; i <= n; ++i) {
        int k;
        cin >> k;
        if (k == -1) {
            sons[0].push_back(i);
        } else {
            sons[k].push_back(i);
        }
    }

    cout << result(0, sons) - 1 << '\n';
    return 0;
}