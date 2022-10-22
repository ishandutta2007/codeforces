#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <iomanip>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <random>
#include <list>
#include <array>
#include <fstream>
#include <chrono>
typedef long long ll;
typedef long double ld;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    vector<int> f(1e6 + 79, 0);
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a2(2 * n);
        for (int i = 0; i < 2 * n; i++)
        {
            pair<int, int> aa;
            cin >> a2[i];
        }
        sort(a2.begin(), a2.end());
        bool answer = false;
        for (int e = 0; e < 2 * n - 1; e++)
        {
            vector<pair<int, int> > ans;
            for (int i = 0; i < 2 * n;i++)
                if (i != e) f[a2[i]]++;
            ans.push_back({ a2.back(), a2[e] });
            int x = a2.back();
            f[x]--;
            int bad = 0, in = 2 * n - 2;
            for (int i = 0; i < n-1; i++, in--)
            {
                while (in == e || !f[a2[in]])
                {
                    in--;
                }
                int s = x - a2[in];
                x = a2[in];
                f[x]--;
                if (f[s] <= 0)
                {
                    bad++;
                    break;
                }
                f[s]--;
                ans.push_back({ x, s });
            }
            for (int i = 0; i < 2 * n; i++) f[a2[i]] = 0;
            if (bad)
                continue;
            answer = true;
            cout << "YES\n";
            cout << ans[0].first + ans[0].second << "\n";
            for (int i = 0; i < n; i++)
            {
                cout << ans[i].first << " " << ans[i].second << "\n";
            }
            break;
        }
        if (!answer) cout << "NO\n";
    }
    return 0;
}