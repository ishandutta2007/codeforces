#include <bits/stdc++.h>
using namespace std;

const int wins[] = {25, 25, 25, 25, 15};

int mat[10][2];
bool ok(int s, int n, int a, int b) {
    int A = 0, B = 0;
    int LA = 1000000, LB = 1000000;
    for (int i = 0; i < n; i++)
        if (s & (1 << i)) a -= wins[i], B += wins[i] - 2, LB = min(LB, wins[i] - 2);
        else b -= wins[i], A += wins[i] - 2, LA = min(LA, wins[i] - 2);
    if (a < 0 || b < 0) return false;

    if (a <= A && b <= B) {
        for (int i = 0; i < n; i++)
            if (s & (1 << i)) {
                mat[i][0] = wins[i];
                mat[i][1] = min(wins[i] - 2, b);
                b -= min(wins[i] - 2, b);
            }
            else {
                mat[i][1] = wins[i];
                mat[i][0] = min(wins[i] - 2, a);
                a -= min(wins[i] - 2, a);
            }
        return true;
    }

    int RA, RB;
    do {
        int _a = a - LA, _b = b;
        if (_a < 0 || _b < 0) break;
        RA = A - LA, RB = B;

        if (_a > _b) {
            if (_a - _b > RA) break;
            RA = _a - _b;
            RB = 0;
            _a = _b;
        }
        else if (_a < _b) {
            if (_b - _a > RB) break;
            RA = 0;
            RB = _b - _a;
            _b = _a;
        }
        else RA = RB = 0;
        for (int i = 0; i < n; i++)
            if (s & (1 << i)) {
                mat[i][0] = wins[i];
                mat[i][1] = min(wins[i] - 2, RB);
                RB -= min(wins[i] - 2, RB);
            }
            else {
                if (wins[i] - 2 == LA) {
                    mat[i][0] = wins[i] - 2 + _a;
                    mat[i][1] = wins[i] + _a;
                    LA = -1;
                }
                else {
                    mat[i][1] = wins[i];
                    mat[i][0] = min(wins[i] - 2, RA);
                    RA -= min(wins[i] - 2, RA);
                }
            }
        return true;
    } while(false);


    do {
        int _a = a, _b = b - LB;
        if (_a < 0 || _b < 0) break;
        RA = A, RB = B - LB;

        if (_a > _b) {
            if (_a - _b > RA) break;
            RA = _a - _b;
            RB = 0;
            _a = _b;
        }
        else if (_a < _b) {
            if (_b - _a > RB) break;
            RA = 0;
            RB = _b - _a;
            _b = _a;
        }
        else RA = RB = 0;
        for (int i = 0; i < n; i++)
            if (!(s & (1 << i))) {
                mat[i][1] = wins[i];
                mat[i][0] = min(wins[i] - 2, RA);
                RA -= min(wins[i] - 2, RA);
            }
            else {
                if (wins[i] - 2 == LB) {
                    mat[i][1] = wins[i] - 2 + _a;
                    mat[i][0] = wins[i] + _a;
                    LB = -1;
                }
                else {
                    mat[i][0] = wins[i];
                    mat[i][1] = min(wins[i] - 2, RB);
                    RB -= min(wins[i] - 2, RB);
                }
            }
        return true;
    } while(false);
    return false;
}

int AA, BB, CC;
int work(int a, int b) {
    int cnt = 0;
    int rt = -10;
    for (int s = 0; s < (1 << 5); s++) {
        int cnt = 0, i;
        for (i = 0; i < 5; i++) {
            if ((1 << i) & s) cnt++;
            if (cnt == 3) {
                i++;
                break;
            }
            if (i - cnt + 1 == 3) {
                i++;
                break;
            }
        }
        if (2 * cnt - i <= rt) continue;
        if (!ok(s, i, a, b)) continue;
        rt = cnt - (i - cnt);
        AA = cnt, BB = i - cnt;
        CC = i;
    }
    return rt;
}

int main() {
    //cout << ok(7, 3, 78, 50) << endl;
    //freopen("input.txt", "r", stdin);
    int t, a, b;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &a, &b);
        int t = work(a, b);
        if (t < -5) printf("Impossible\n");
        else {
            printf("%d:%d\n", AA, BB);
            for (int i = 0; i < CC; i++) printf("%d:%d ", mat[i][0], mat[i][1]);
            puts("");
        }
    }
    return 0;
}