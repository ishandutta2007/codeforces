#include<bits/stdc++.h>
#define fi first
#define se second

using namespace std;
typedef long long LL;
typedef pair<int,int> P;

const int maxn = 2e5 + 5;
const int mod = 1e9 + 7;
const int B = 300;

int a[maxn], b[maxn], ff[maxn], mark[maxn], st[maxn];
int f[B + 5][B + 5];

void fadd(int t, int x)
{
    t += a[x];
    while (t < maxn) {
        ff[t] += 1;
        if (t + b[x] < maxn) ff[t + b[x]] -= 1;
        t += a[x] + b[x];
    }
}

void fdel(int t, int x)
{
    t += a[x];
    while (t < maxn) {
        ff[t] -= 1;
        if (t + b[x] < maxn) ff[t + b[x]] += 1;
        t += a[x] + b[x];
    }
}

void gadd(int x, int t)
{
    int m = a[x] + b[x];
    for (int i = 0, j = (t + a[x]) % m; i < b[x]; i++, j = (j + 1) % m) f[m][j]++;
}

void gdel(int x, int t)
{
    int m = a[x] + b[x];
    for (int i = 0, j = (t + a[x]) % m; i < b[x]; i++, j = (j + 1) % m) f[m][j]--;
}

int qry(int t)
{
    int r = 0;
    for (int i = 2; i <= B; i++) r += f[i][t % i];
    return r;
}

void solve()
{
    int n, m, val = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
        if (a[i] + b[i] <= B) {
            mark[i] = 1;
        }
    }
    for (int i = 1; i <= m; i++) {
        int op, x;
        cin >> op >> x;
        val += ff[i];
        if (mark[x]) {
            if (op == 1) {
                st[x] = i;
                gadd(x, i);
            } else {
                gdel(x, st[x]);
            }
        } else {
            if (op == 1) {
                st[x] = i;
                fadd(i, x);
            } else {
                int w = (i - st[x]) % (a[x] + b[x]);
                if (w >= a[x]) val--;
                fdel(st[x], x);
            }
        }

        cout << val + qry(i) << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    while (t--) solve();
    return 0;
}