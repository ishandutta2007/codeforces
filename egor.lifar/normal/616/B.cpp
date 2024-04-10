#include <iostream>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <unordered_map>
#include <cstring>
#include <string.h>


using namespace std;


int n, m;
int c[1001][1001];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &c[i][j]);
        }
    }
    int t1 = 0;
    for (int i = 0; i < n; i++) {
        int t = 1000 * 1000 * 1000 + 1;
        for (int j = 0; j < m; j++) {
            t = min(t, c[i][j]);
        }
        t1 = max(t1, t);
    }
    cout << t1 << endl;
    return 0;
}