#include <iostream>
#include <sstream>

using namespace std;

int a[201], b[201], n, m, f[201] = {0};
stringstream ss;

int main(void)
{
    cin >> n >> m;
    int i, j = 0, k, t, q, ans = 0;
    for (i = 1; i <= m; ++i)
    {
        cin >> k;
        for (t = 0; t < k; ++t)
        {
            cin >> q;
            f[q] = ++j;
        }
    }
    for (i = j + 1; i <= n; ++i)
        if (f[i] > 0)
        {
            ++ans;
            for (k = 1; k <= n; ++k)
                if (f[k] == 0)
                {
                    ss << i << ' ' << k << endl;
                    f[k] = f[i];
                    f[i] = 0;
                    break;
                }
        }
    ++j;
    for (i = 1; i < j; ++i)
        if (f[i] != i)
        {
            ++ans;
            ss << i << ' ' << j << endl;
            f[j] = f[i];
            k = i;
            while (k != f[j])
            {
                for (t = 1; t < j; ++t)
                    if (f[t] == k)
                    {
                        ++ans;
                        ss << t << ' ' << k << endl;
                        f[k] = k;
                        k = t;
                        break;
                    }
            }
            ++ans;
            ss << j << ' ' << k << endl;
            f[k] = k;
        }
    cout << ans << endl;
    cout << ss.str();
    return 0;
}