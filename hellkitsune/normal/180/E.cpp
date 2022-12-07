#include <iostream>
#include <vector>

using namespace std;

const int e = 1e5;
int n, m, k, mx = 1;
int a[2*e], l[e], r[e], c[e], pos[e], d[e];
vector<int> v[e];

int main(void)
{
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        --a[i];
    }
    for (int i = 0; i < m; ++i)
        r[i] = -1;
    for (int i = 0; i < n; ++i)
        if (r[a[i]] == -1)
        {
            l[a[i]] = i;
            r[a[i]] = i;
            c[a[i]] = 1;
            d[a[i]] = 0;
            pos[a[i]] = 0;
        }
        else
        {
            if (a[i - 1] == a[i])
            {
                ++r[a[i]];
                if (++c[a[i]] > mx)
                    mx = c[a[i]];
            }
            else
            {
                v[a[i]].push_back(i);
                d[a[i]] += i - r[a[i]] - 1;
                r[a[i]] = i;
                ++c[a[i]];
                while (d[a[i]] > k)
                {
                    while (a[l[a[i]]] == a[i])
                    {
                        --c[a[i]];
                        ++l[a[i]];
                    }
                    d[a[i]] -= v[a[i]][pos[a[i]]] - l[a[i]];
                    l[a[i]] = v[a[i]][pos[a[i]]++];
                }
                if (c[a[i]] > mx)
                    mx = c[a[i]];
            }
        }
    cout << mx << endl;
    return 0;
}