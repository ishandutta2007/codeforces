#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
struct node {
    double x, y;
    inline double angle() const {
        return atan2(y, x);
    }
    inline double len() {
        return sqrt(x * x + y * y);
    }
} a[3010];
int id[3010];
inline node operator + (const node &a, const node &b) {
    return {a.x + b.x, a.y + b.y};
}
inline node operator - (const node &a, const node &b) {
    return {a.x - b.x, a.y - b.y};
}
inline double operator * (const node &a, const node &b) {
    return a.x * b.x + a.y * b.y;
}
inline double operator ^ (const node &a, const node &b) {
    return a.x * b.y - a.y * b.x;
}
int n;
double R;
bool able[3010][3010];
pair < double, int > cur[9010];
int tot;
int main() {
    scanf("%d%lf", &n, &R);
    for (int i = 1; i <= n; i++) scanf("%lf%lf", &a[i].x, &a[i].y);
    memset(able, 1, sizeof able);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < n; j++) id[j] = j < i ? j : j + 1;
        int ccnt = 0;
        tot = 0;
        for (int j = 1; j <= n; j++) if (i != j) {
            node delta = a[j] - a[i];
            double qwq = delta.angle();
            double dis = delta.len();
            if (qwq < 0) qwq += 2 * PI;
            cur[++tot] = {qwq, j};
            if (dis < R + 1e-7) continue;
            double d = asin(R / dis);
            double l = qwq - d, r = qwq + d;
            if (l < 0) l += 2 * PI;
            if (r > 2 * PI) r -= 2 * PI;
            if (l <= r) ccnt++;
            cur[++tot] = {l, -1};
            cur[++tot] = {r, -2};
            // cerr << i << ' ' << j << ' ' << qwq << ' ' << l << ' ' << r << endl;
        }
        sort(cur + 1, cur + 1 + tot);
        for (int j = 1; j <= tot; j++) {
            if (cur[j].second == -1) ccnt--;
            else if (cur[j].second == -2) ccnt++;
            else if (ccnt) {
                // cerr << "ban " << i << ' ' << cur[j].second << endl;
                able[i][cur[j].second] = able[cur[j].second][i] = 0;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++) ans += able[i][j];
    cout << ans << endl;
}