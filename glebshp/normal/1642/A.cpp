#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
 
using namespace std;
 
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

int getans(int maxy, int px1, int py1, int px2, int py2) {
    if (py1 < maxy || py2 < maxy) {
        return 0;
    }
    return abs(px1 - px2);
}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int tc;
    scanf("%d", &tc);
    for (int tnum = 0; tnum < tc; tnum++) {
        int px1, px2, px3;
        int py1, py2, py3;
        scanf("%d%d%d%d%d%d", &px1, &py1, &px2, &py2, &px3, &py3);

        int maxy = max(max(py1, py2), py3);

        int ans = getans(maxy, px1, py1, px2, py2) + getans(maxy, px2, py2, px3, py3) + getans(maxy, px1, py1, px3, py3);
        printf("%d\n", ans);
    }

    return 0;
}