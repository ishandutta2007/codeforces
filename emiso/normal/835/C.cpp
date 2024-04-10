#include <bits/stdc++.h>

#define MN 110
#define w1 while(1)
#define debug(a) cerr << a << endl
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

int n, q, c, x, y, s, x1, y1, x2, y2;
int grid[MN][MN][11], acum[MN][MN][11];
ll t;
//char s[MN]; string str;

int main() {

    scanf("%d %d %d", &n, &q, &c);

    for(int i=0; i<n; i++) {
        scanf("%d %d %d", &x, &y, &s);
        grid[x][y][s]++;
    }

    for(int S=0;S<=c;S++) {
        for(int i=1; i<=100; i++) for(int j=1;j<=100; j++) {
            acum[i][j][S] = grid[i][j][S];
            acum[i][j][S] += acum[i-1][j][S];
            acum[i][j][S] += acum[i][j-1][S];
            acum[i][j][S] -= acum[i-1][j-1][S];
        }
    }

    for(int Q=0; Q<q; Q++) {
        scanf("%lld %d %d %d %d", &t, &x1, &y1, &x2, &y2);
        ll ans = 0;

        for(int S=0;S<=c;S++) {
            ll x = acum[x2][y2][S];
            x -= acum[x1-1][y2][S];
            x -= acum[x2][y1-1][S];
            x += acum[x1-1][y1-1][S];

            ans += (x * ((S + t) % (c + 1)));
        }

        printf("%lld\n", ans);
    }
    return 0;
}