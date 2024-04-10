#include <iostream>
#include <algorithm>

using namespace std;

int lg[300000];
int n;
int st[20][300000];
int v[300000];
int r[300000];

void buildSparseTable()
{
    lg[1] = 0;
    for (int i = 2; i <= n; i++) lg[i] = lg[i / 2] + 1;
    for (int i = 0; i < n; i++) st[0][i] = v[i];
    for (int i = 1; i < 20; i++)
        for (int j = 0; j < n; j++)
        {
            int nj = j + (1 << (i - 1));
            if (nj < n) st[i][j] = min(st[i - 1][j], st[i - 1][nj]);
                else st[i][j] = st[i - 1][j];
        }
}

int callRMQ(int l, int r)
{
    int w = lg[r - l + 1];
    return min(st[w][l], st[w][r - (1 << w) + 1]);
}

bool yesLeft(int a, int e) { return callRMQ(a, e) == v[e]; }
int findLeft(int l, int r, int e)
{
    if (l == r) return l;
    if (l + 1 == r) return yesLeft(l, e) ? l : r;
    int m = (l + r) / 2;
    if (yesLeft(m, e)) return findLeft(l, m, e); else return findLeft(m, r, e);
}

bool yesRight(int a, int e) { return callRMQ(e, a) == v[e]; }
int findRight(int l, int r, int e)
{
    if (l == r) return l;
    if (l + 1 == r) return yesRight(r, e) ? r : l;
    int m = (l + r) / 2;
    if (yesRight(m, e)) return findRight(m, r, e); else return findRight(l, m, e);
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) cin >> v[i];
    buildSparseTable();
    for (int i = 0; i < n; i++)
    {
        int vl = findLeft(0, i, i), vr = findRight(i, n - 1, i);
        r[vr - vl + 1] = max(r[vr - vl + 1], v[i]);
    }
    for (int i = n - 1; i > 0; i--) r[i] = max(r[i], r[i + 1]);
    for (int i = 1; i <= n; i++) cout << r[i] << " ";
}