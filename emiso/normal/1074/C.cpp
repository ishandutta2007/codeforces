#include <bits/stdc++.h>

#define MN 301000

using namespace std;
typedef long long ll;

ll ans, res[MN];
int n, x[MN], y[MN], minx = 1000000000, maxx = -1000000000, miny = 1000000000, maxy = -1000000000, q;

ll dist(int i, int j) {
    return abs(x[i] - x[j]) + abs(y[i] - y[j]);
}

vector<int> possib, Minx, Miny, Maxx, Maxy;

int main() {
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d %d", &x[i], &y[i]);
        minx = min(minx, x[i]);
        maxx = max(maxx, x[i]);
        miny = min(miny, y[i]);
        maxy = max(maxy, y[i]);
    }

    for(int i = 0; i < n; i++) {
        ans += dist(i, (i + 1) % n);
    }

    for(int i = 4; i <= n; i++) {
        res[i] = ans;
    }

    for(int i = 0; i < n; i++) {
        if(x[i] == minx) Minx.push_back(y[i]);
        if(y[i] == miny) Miny.push_back(x[i]);

        if(x[i] == maxx) Maxx.push_back(y[i]);
        if(y[i] == maxy) Maxy.push_back(x[i]);
    }
    sort(Minx.begin(), Minx.end());
    sort(Miny.begin(), Miny.end());
    sort(Maxx.begin(), Maxx.end());
    sort(Maxy.begin(), Maxy.end());

    //printf("%d %d %d %d\n", minx, maxx, miny, maxy);

    for(int i = 0; i < n; i++) {
        if(
            (x[i] == minx && (y[i] == Minx[0] || y[i] == Minx.back())) ||
            (x[i] == maxx && (y[i] == Maxx[0] || y[i] == Maxx.back())) ||
            (y[i] == miny && (x[i] == Miny[0] || x[i] == Miny.back())) ||
            (y[i] == maxy && (x[i] == Maxy[0] || x[i] == Maxy.back())) ) {
                possib.push_back(i);
                //printf("%d = %d %d\n", i, x[i], y[i]);
            }
    }

    ans = -1000000000;
    q = possib.size();

    for(int i = 0; i < q; i++) {
        for(int j = i + 1; j < q; j++) {
            for(int k = 0; k < n; k++) {
                ans = max(ans, dist(possib[i], possib[j]) + dist(possib[j], k) + dist(k, possib[i]));
            }
        }
    }
    res[3] = ans;


    for(int i = 3; i <= n; i++)
        printf("%lld ", res[i]);
    return 0;
}