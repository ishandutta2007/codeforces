#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct mp
{
    int dif, count;
    mp(int a, int b)
    {
        dif = a;
        count = b;
    }
};

bool operator < (const mp &a, const mp &b)
{
    return a.dif < b.dif;
}

int n, m, k, mx = 0;
int a[10][100], b[10][100], c[10][100];
vector<mp> v;

int main(void)
{
    string s;
    int i, j, p;
    cin >> n >> m >> k;
    for (i = 0; i < n; ++i)
    {
        cin >> s;
        for (j = 0; j < m; ++j)
            cin >> a[i][j] >> b[i][j] >> c[i][j];
    }
    for (i = 0; i < n; ++i)
        for (j = 0; j < n; ++j)
            if (i != j)
            {
                int q = k, cur = 0;
                v.clear();
                for (p = 0; p < m; ++p)
                    if (b[j][p] - a[i][p] > 0)
                        v.push_back(mp(b[j][p] - a[i][p], c[i][p]));
                sort(v.begin(), v.end());
                for (int ii = v.size() - 1; ii >= 0; --ii)
                    if (v[ii].count >= q)
                    {
                        cur += v[ii].dif * q;
                        break;
                    }
                    else
                    {
                        cur += v[ii].dif * v[ii].count;
                        q -= v[ii].count;
                    }
                if (cur > mx)
                    mx = cur;
            }
    cout << mx;
    return 0;
}