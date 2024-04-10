#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

vector<int> solve(int n, int m, vector<string> &v)
{
    vector<int> ans;
    if (m & 1)
    {
        for (int i = 0; i < m + 1; i++) ans.push_back((i % 2));
        return ans;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j && v[i][j] == v[j][i])
            {
                for (int k = 0; k < m + 1; k++)
                {
                    ans.push_back(((k % 2) ? i : j));
                }
                return ans;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        int a = -1, b = -1;
        for (int j = 0; j < n; j++)
        {
            if (v[i][j] == 'a') a = j;
            if (v[i][j] == 'b') b = j;
        }
        if (a != -1 && b != -1)
        {
            vector<int> ans(m + 1); ans[m / 2] = i;
            for (int in = (m / 2) - 1, cnt = 0; in >= 0; in--, cnt++)
            {
                if (cnt & 1) ans[in] = i;
                else ans[in] = a;
            }
            for (int in = (m / 2) + 1, cnt = 0; in < m + 1; in++, cnt++)
            {
                if (cnt & 1) ans[in] = i;
                else ans[in] = b;
            }
            return ans;
        }
    }
    return {};
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<string> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        vector<int> ans = solve(n, m, v);
        if (ans.size())
        {
            cout << "YES\n";
            for (int k = 0; k < ans.size(); k++) cout << ans[k] + 1 << " ";
            cout << "\n";
            //for (int k = 0; k < ans.size() - 1; k++) cout << v[ans[k]][ans[k + 1]];
            //cout << "\n";
        }
        else cout << "NO\n";
    }
    return 0;
}