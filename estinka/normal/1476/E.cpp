#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <queue>
typedef long long ll;
typedef long double ld;
using namespace std;

void end()
{
    cout << "NO\n";
    exit(0);
}
const int maxn = 1e5 + 79;
vector<vector<int> > g(maxn);
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> p(n), s(m);
    map<string, int> mm;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
        mm[p[i]] = i;
    }
    vector<int> d(n, 0);
    for (int i = 0, mt; i < m; i++)
    {
        cin >> s[i] >> mt; mt--;
        bool match = 0;
        for (int mask = 0; mask < (1 << k); mask++)
        {
            string s2 = s[i];
            for (int j = 0; j < k; j++) if ((1 << j) & mask) s2[j] = '_';
            if (s2 == p[mt]) match = true;
            else if (mm.count(s2))
            {
                g[mt].push_back(mm[s2]);
                d[mm[s2]]++;
            }
        }
        if (!match) end();
    }
    vector<int> st, ts;
    for (int i = 0; i < n; i++) if (!d[i]) st.push_back(i);
    while (!st.empty())
    {
        int k = st.back();
        st.pop_back();
        ts.push_back(k);
        for (int i : g[k])
        {
            d[i]--;
            if (!d[i]) st.push_back(i);
        }
    }
    if (ts.size() != n) end();
    cout << "YES\n";
    for (int i = 0; i < n; i++) cout << ts[i] + 1 << " ";
    cout << "\n";
    return 0;
}