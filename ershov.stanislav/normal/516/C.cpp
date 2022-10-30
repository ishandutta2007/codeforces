#include <bits/stdc++.h>

#define mp make_pair
#define fs first
#define sc second
#define pb push_back

#define y0 yy0
#define y1 yy1
#define next _next
#define prev _prev
#define link _link
#define hash _hash

#define sz(s) int((s).size())
#define len(s) int((s).size())
#define all(s) (s).begin(), (s).end()

typedef long long ll;
typedef long double ld;

const ll INF = 1e9;
const ll lINF = 1e18;
const double EPS = 1e-12;

using namespace std;

int n, m, d[222222], h[222222];
ll sum1[222222], sum2[222222];
int sparse1[21][222222], sparse2[21][222222];
int mx[222222];

int get_min(int i, int j) {
    int mn1 = sparse1[mx[j-i]][i];
    if (sum1[mn1] > sum1[sparse1[mx[j-i]][j - (1 << mx[j-i])]]) {
        mn1 = sparse1[mx[j-i]][j - (1 << mx[j-i])];
    }
    return mn1;
}
int get_max(int i, int j) {
    int mx1 = sparse2[mx[j-i]][i];
    if (sum2[mx1] < sum2[sparse2[mx[j-i]][j - (1 << mx[j-i])]]) {
        mx1 = sparse2[mx[j-i]][j - (1 << mx[j-i])];
    }
    return mx1;
}
ll get_ans(int i, int j) {
    ll mx1, mn1;
    mn1 = get_min(i, j);
    mx1 = get_max(i, j);

//    cout << i << ' ' << j << ": " << mn1 << ' ' << mx1 << endl;

    ll res = 0;
    if (mx1 > i) res = max(res, sum2[mx1] - sum1[get_min(i, mx1)]);
//    cout << get_min(i, mx1) << endl;
    if (mn1 == j-1) {
        return res;
    }
    res = max(res, sum2[get_max(mn1 + 1, j)] - sum1[mn1]);
//    cout << get_max(mn1 + 1, j) << endl;
    return res;
}

int main() {
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif

    for (int i = 2; i < 222222; i++) {
        mx[i] = mx[i - 1];
        if ((1 << (mx[i] + 1)) <= i) {
            mx[i]++;
        }
    }
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &d[i]);
        d[i + n] = d[i];
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &h[i]);
        h[i + n] = h[i];
    }
    for (int i = 1; i <= 2*n + 10; i++) {
        sum1[i + 1] = sum1[i] + d[i];
        sum2[i + 1] = sum1[i + 1];
    }
    for (int i = 1; i <= 2 * n + 10; i++) {
        sum1[i] -= 2*h[i];
        sum2[i] += 2*h[i];
        sparse1[0][i] = i;
        sparse2[0][i] = i;
    }

//    for (int i = 1; i <= 2*n; i++) {
//        cout << sum1[i] << ' ';
//    }
//    cout << endl;
//    for (int i = 1; i <= 2*n; i++) {
//        cout << sum2[i] << ' ';
//    }
//    cout << endl;

    for (int i = 1; i < 21; i++) {
        for (int j = 1; j <= 2*n + 10; j++) {
            sparse1[i][j] = sparse1[i-1][j];
            sparse2[i][j] = sparse2[i-1][j];
            if (j + (1 << (i - 1)) < 222222) {
                if (sum1[sparse1[i-1][j + (1 << (i - 1))]] < sum1[sparse1[i][j]]) {
                    sparse1[i][j] = sparse1[i-1][j + (1 << (i - 1))];
                }
                if (sum2[sparse2[i-1][j + (1 << (i - 1))]] > sum2[sparse2[i][j]]) {
                    sparse2[i][j] = sparse2[i-1][j + (1 << (i - 1))];
                }
            }
        }
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        if (a > b) {
            cout << get_ans(b + 1, a) << endl;
        } else {
            cout << get_ans(b + 1, a + n) << endl;
        }
    }

    return 0;
}