#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <vector>


using namespace std;


int n, m, k;
bool b[100000][10];
int ans[100000];
int d[100000][10], l[100000];


int main() {
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int a;
            cin >> a;
            if (a == 1) {
                b[i][j] = true;
            } else {
                b[i][j] = false;
            }
        }
    }
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        d[a][b]++;
        l[b]++;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (b[i][j]) {
                ans[i] += l[j] - d[i][j];
            }
        }
        cout << ans[i] << ' ';
    }
    cout << endl;
    return 0;
}