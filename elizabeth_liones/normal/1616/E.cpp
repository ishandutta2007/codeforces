#include <algorithm>
#include <iostream>
#include <string>
#include <random>
#include <chrono>
#include <vector>
#include <cmath>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

const int abc = 26;
const ll inf = 1e18;
int maxn;
vector<int> st;
void upd(int i, int d)
{
    for (i += maxn; i > 0; i >>= 1) st[i] += d;
}
int query(int l, int r)
{
    int sum = 0;
    for (l += maxn, r += maxn + 1; l < r; l >>= 1, r >>= 1)
    {
        if (l & 1) sum += st[l++];
        if (r & 1) sum += st[--r];
    }
    return sum;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        maxn = 1;
        while (maxn < n) maxn <<= 1;
        st.assign(maxn * 2, 0);
        string s, t;
        cin >> s >> t;
        vector<int> id(abc, 0);
        vector<vector<int> > o(abc);
        for (int i = 0; i < n; i++)
        {
            upd(i, 1);
            o[s[i] - 'a'].push_back(i);
        }
        ll ans = inf, sum = 0;
        for (int i = 0; i < n; i++)
        {
            int x = n + 1;
            for (int j = 0; j < t[i] - 'a'; j++)
            {
                if (id[j] != o[j].size()) x = min(x, o[j][id[j]]);
            }
            if (x < n + 1)
            {
                ans = min(ans, sum + query(0, x - 1));
            }
            int c = t[i] - 'a';
            if (id[c] == o[c].size()) break;
            sum += query(0, o[c][id[c]] - 1);
            upd(o[c][id[c]], -1);
            id[c]++;
        }
        cout << "                   ";
        cout << (ans == inf ? -1 : ans) << "\n";
    }
    return 0;
}