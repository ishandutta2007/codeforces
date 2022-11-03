#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int M = 1e9 + 7;
const int N = 100 + 13;
const int INF = 1e9 + 13;

struct P {
    ld px, py, pz;

    P() {};

    P(ld x, ld y, ld z) : px(x), py(y), pz(z) {};
};

P mul(P p, ld x) {
    return P(p.px * x, p.py * x, p.pz * x);
}

P sum(P p, P q) {
    return P(p.px + q.px, p.py + q.py, p.pz + q.pz);
}

P dp[N][N][N];

P calc(int x, int y, int z) {
    if(dp[x][y][z].px > -0.5)
        return dp[x][y][z];


    if(x == 0 && y == 0)
        return P(0, 0, 1);

    if(x == 0 && z == 0)
        return P(0, 1, 0);

    if(y == 0 && z == 0)
        return P(1, 0, 0);

    int s = x * y + x * z + y * z;

    P res(0, 0, 0);

    if(x > 0 && y > 0)
        res = sum(res, mul(calc(x, y - 1, z), x * y * 1.0 / s));

    if(x > 0 && z > 0)
        res = sum(res, mul(calc(x - 1, y, z), x * z * 1.0 / s));

    if(z > 0 && y > 0)
        res = sum(res, mul(calc(x, y, z - 1), y * z * 1.0 / s));

    return dp[x][y][z] = res;
}

int main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    int x, y, z;
    cin >> x >> y >> z;

    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            for(int l = 0; l < N; l++)
                dp[i][j][l] = P(-1, -1, -1);

    calc(x, y, z);

    cout << setprecision(20) << fixed << dp[x][y][z].px << ' ' << dp[x][y][z].py << ' ' << dp[x][y][z].pz << endl;
}