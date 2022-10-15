#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 123456789;

int getInt() { int n; scanf("%d", &n); return n; }

int main()
{
    int n = getInt();
    vector <int> a(n), b(n), u(n), c(n);
    for (int i = 0; i < n; i++) a[i] = getInt() - 1;
    for (int i = 0; i < n; i++) b[i] = getInt() - 1;
    for (int i = 0; i < n; i++) u[a[i]] = i;
    for (int i = 0; i < n; i++) c[i] = -u[b[i]];
    vector <int> q(n + 1);
    q[0] = -INF;
    for (int i = 1; i <= n; i++) q[i] = INF;
    for (int i = 0; i < n; i++)
    {
        int j = int(upper_bound(q.begin(), q.end(), c[i]) - q.begin());
        if (q[j - 1] < c[i] && c[i] < q[j]) q[j] = c[i];
    }
    for (int i = n; i > 0; i--) if (q[i] != INF) { printf("%d", i); break; }
}