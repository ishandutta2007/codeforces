#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#define int long long

using namespace std;

set<int> s;
vector <int> d;

void razl(int n)
{
    for (int i = 2; i * i <= n; i++)
        while (n % i == 0)
            s.insert(i),
            n /= i;
    if (n != 1) s.insert(n);
}

const int INF = 123456789012345678;
int qdp[100][3], odp[100][3];
int n, a, b;

int getGrowth(int q, int num)
{
    if (num % d[q] == 0) return 0;
    if ((num - 1) % d[q] == 0) return b;
    if ((num + 1) % d[q] == 0) return b;
    return INF;
}

main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> a >> b;
    vector <int> v(n);
    s.clear();
    for (int i = 0; i < n; i++) cin >> v[i];
    razl(v[0]); razl(v[0] + 1); razl(v[0] - 1);
    razl(v[n - 1]); razl(v[n - 1] + 1); razl(v[n - 1] - 1);
    for (auto it: s) d.push_back(it);
    int m = d.size();
    for (int i = 0; i < m; i++)
        qdp[i][2] = qdp[i][0] = getGrowth(i, v[0]),
        qdp[i][1] = a;
    for (int i = 1; i < n; i++)
        for (int j = 0; j < m; j++)
            odp[j][0] = qdp[j][0],
            odp[j][1] = qdp[j][1],
            odp[j][2] = qdp[j][2],
            qdp[j][0] = min(INF, odp[j][0] + getGrowth(j, v[i])),
            qdp[j][1] = min(odp[j][1], odp[j][0]) + a,
            qdp[j][2] = min(qdp[j][0], min(odp[j][1], odp[j][2]) + getGrowth(j, v[i]));
    int res = INF;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < 3; j++)
            res = min(res, qdp[i][j]);
    cout << res;
}