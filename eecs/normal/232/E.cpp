#include <bits/stdc++.h>
using namespace std;

const int maxn = 510, maxq = 600010;
int n, m, q, tim, vis1[maxn][maxn], vis2[maxn][maxn];
bool ans[maxq];
array<int, 4> a[maxq];
char s[maxn][maxn];
bitset<maxn> b1[maxn][maxn], b2[maxn][maxn];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> s[i] + 1;
    }
    function<void(int, int, int, int, vector<int>&)> solve = [&](int l1, int r1, int l2, int r2, vector<int> &Q) {
        if (Q.empty()) return;
        if (r1 - l1 > r2 - l2) {
            int mid = (l1 + r1) / 2;
            vector<int> Q1, Q2, Q3;
            for (int i : Q) {
                (a[i][2] < mid ? Q1 : a[i][0] > mid ? Q2 : Q3).push_back(i);
            }
            solve(l1, mid - 1, l2, r2, Q1), solve(mid + 1, r1, l2, r2, Q2);
            if (Q3.empty()) return;
            for (int i : Q3) {
                b1[a[i][0]][a[i][1]].reset(), b2[a[i][2]][a[i][3]].reset();
            }
            for (int p = l2; p <= r2; p++) if (s[mid][p] == '.') {
                vis1[mid][p] = ++tim;
                for (int i = mid; i >= l1; i--) {
                    for (int j = p; j >= l2; j--) {
                        if (s[i][j] == '.' && vis1[i][j] == tim) {
                            b1[i][j].set(p), vis1[i - 1][j] = vis1[i][j - 1] = tim;
                        }
                    }
                }
                vis2[mid][p] = ++tim;
                for (int i = mid; i <= r1; i++) {
                    for (int j = p; j <= r2; j++) {
                        if (s[i][j] == '.' && vis2[i][j] == tim) {
                            b2[i][j].set(p), vis2[i + 1][j] = vis2[i][j + 1] = tim;
                        }
                    }
                }
            }
            for (int i : Q3) {
                ans[i] = (b1[a[i][0]][a[i][1]] & b2[a[i][2]][a[i][3]]).any();
            }
        } else {
            int mid = (l2 + r2) / 2;
            vector<int> Q1, Q2, Q3;
            for (int i : Q) {
                (a[i][3] < mid ? Q1 : a[i][1] > mid ? Q2 : Q3).push_back(i);
            }
            solve(l1, r1, l2, mid - 1, Q1), solve(l1, r1, mid + 1, r2, Q2);
            if (Q3.empty()) return;
            for (int i : Q3) {
                b1[a[i][0]][a[i][1]].reset(), b2[a[i][2]][a[i][3]].reset();
            }
            for (int p = l1; p <= r1; p++) if (s[p][mid] == '.') {
                vis1[p][mid] = ++tim;
                for (int i = p; i >= l1; i--) {
                    for (int j = mid; j >= l2; j--) {
                        if (s[i][j] == '.' && vis1[i][j] == tim) {
                            b1[i][j].set(p), vis1[i - 1][j] = vis1[i][j - 1] = tim;
                        }
                    }
                }
                vis2[p][mid] = ++tim;
                for (int i = p; i <= r1; i++) {
                    for (int j = mid; j <= r2; j++) {
                        if (s[i][j] == '.' && vis2[i][j] == tim) {
                            b2[i][j].set(p), vis2[i + 1][j] = vis2[i][j + 1] = tim;
                        }
                    }
                }
            }
            for (int i : Q3) {
                ans[i] = (b1[a[i][0]][a[i][1]] & b2[a[i][2]][a[i][3]]).any();
            }
        }
    };
    cin >> q;
    vector<int> Q;
    for (int i = 1; i <= q; i++) {
        cin >> a[i][0] >> a[i][1] >> a[i][2] >> a[i][3];
        Q.push_back(i);
    }
    solve(1, n, 1, m, Q);
    for (int i = 1; i <= q; i++) {
        cout << (ans[i] ? "Yes\n" : "No\n");
    }
    return 0;
}