#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
#include <time.h>
#include <queue>

using namespace std;

int ans = -1;
int maxh = -1;

void get(int tl, int tr, int a, int b, int h) {
    if (tl == tr) {
        maxh = h;
        return;
    }

    if (tl <= b && b <= tr) ans = max(ans, h);

    int tm = (tl + tr) / 2;
    if (a <= tm) get(tl, tm, a, b, h + 1);
    else get(tm + 1, tr, a, b, h + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    
    int n, a, b;
    cin >> n >> a >> b;

    get(0, n - 1, a - 1, b - 1, 0);

    if (ans == 0) cout << "Final!\n";
    else cout << maxh - ans << '\n';

    return 0;
}