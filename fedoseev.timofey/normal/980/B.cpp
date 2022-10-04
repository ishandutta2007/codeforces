#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <ctime>
#include <random>
#include <cmath>
#include <bitset>
#include <iomanip>
#include <list>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector <vector <char>> f(4, vector <char>(n, '.'));
    if (k % 2 == 0) {
        for (int i = 1; i <= k / 2; ++i) {
            f[1][i] = '#';
            f[2][i] = '#';
        }
    }
    else {
        if (k > 3) {
            int x = (k + 1) / 2;
            for (int i = 1; i <= x; ++i) {
                f[1][i] = '#';
                f[2][i] = '#';
            }
            f[1][2] = '.';
        }
        else if (k == 3) {
            int cen = n / 2;
            f[2][cen] = '#';
            f[1][cen - 1] = '#';
            f[1][cen + 1] = '#';
        }
        else {
            int cen = n / 2;
            f[1][cen] = '#';
        }
    }
    cout << "YES\n";
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << f[i][j];
        }
        cout << '\n';
    }
}