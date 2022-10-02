#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
#include <map>
#include <set>
#include <assert.h>


using namespace std;


int n;
int a[1000][1000];

int main() {
    cin >> n;
    int s = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        s += a[i][i];
    }
    s %= 2;
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int t;
        scanf("%d", &t);
        if (t == 1 || t == 2) {
            s = 1 - s;
            int a;
            scanf("%d", &a);
        } else {
            printf("%d", s);
        }
    }
    cout << endl;
    return 0;
}