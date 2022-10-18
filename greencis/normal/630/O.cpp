#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int,int> pii;

ld px, py, vx, vy, a, b, c, d;
ld p[7][2];

int main()
{
    cin >> px >> py >> vx >> vy >> a >> b >> c >> d;
    p[0][0] = 0; p[0][1] = b;
    p[1][0] = -a/2; p[1][1] = 0;
    p[2][0] = -c/2; p[2][1] = 0;
    p[3][0] = -c/2; p[3][1] = -d;
    p[4][0] = c/2; p[4][1] = -d;
    p[5][0] = c/2; p[5][1] = 0;
    p[6][0] = a/2; p[6][1] = 0;

    ld angle = atan2l(vy, vx) - acos(-1) / 2;
    for (int i = 0; i < 7; ++i) {
        ld x = p[i][0] * cosl(angle) - p[i][1] * sinl(angle);
        ld y = p[i][1] * cosl(angle) + p[i][0] * sinl(angle);
        p[i][0] = x + px;
        p[i][1] = y + py;
        cout << setprecision(17) << fixed << p[i][0] << " ";
        cout << setprecision(17) << fixed << p[i][1] << "\n";
    }


    return 0;
}