#include <iostream>
#include <vector>

using namespace std;

main()
{
    long long n;
    cin >> n;
    vector <long long> v(n), d(n), r(n), ans, out(n), w(n);
    for (long long i = 0; i < n; i++)
        cin >> v[i] >> d[i] >> r[i];
    for (long long i = 0; i < n; i++) out[i] = 0;
    for (long long i = 0; i < n; i++)
    {
        for (long long j = 0; j < n; j++) w[i] = 0;
        if (out[i] == 1) continue;
        ans.push_back(i);
        for (long long j = i + 1; j < n; j++)
        {
            if (out[j] == 1) continue;
            r[j] -= v[i];
            v[i]--;
            if (v[i] == 0) break;
        }
        w[i] = 0;
        for (long long j = i + 1; j < n; j++)
        {
            w[j] = w[j - 1];
            r[j] -= w[j];
            if (out[j] == 1) continue;
            if (r[j] < 0)
            {
                w[j] += d[j];
                out[j] = 1;
            }
        }
    }
    cout << ans.size() << endl;
    for (long long i = 0; i < ans.size(); i++) cout << ans[i] + 1 << " ";
}