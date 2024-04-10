#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

const int maxn = 3e5 + 5;
int n, k;
vector<int> maxi(int i, vector<int>& a, vector<int>& b)
{
    if (a.empty() || b.empty()) return {};
    if (i == -1)
    {
        return { a[0], b[0] };
    }
    vector<int> a0, a1, b0, b1;
    for (int aa : a)
    {
        if (aa & (1 << i)) a1.push_back(aa);
        else a0.push_back(aa);
    }
    for (int bb : b)
    {
        if (bb & (1 << i)) b1.push_back(bb);
        else b0.push_back(bb);
    }
    if (k & (1 << i))
    {
        vector<int> v01 = maxi(i - 1, a0, b1);
        vector<int> v10 = maxi(i - 1, a1, b0);
        return v01.size() > v10.size() ? v01 : v10;
    }
    if (a0.size() && b1.size()) return { a0[0], b1[0] };
    if (a1.size() && b0.size()) return { a1[0], b0[0] };
    vector<int> v00 = maxi(i - 1, a0, b0);
    vector<int> v11 = maxi(i - 1, a1, b1);
    return v00.size() > v11.size() ? v00 : v11;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    vector<int> a(n);
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        m[a[i]] = i;
    }
    if (!k)
    {
        cout << n << "\n";
        for (int i = 0; i < n; i++) cout << i + 1 << " \n"[i == n - 1];
        return 0;
    }
    int h = 0;
    while ((1 << h) <= k) h++;
    h--; // most significant bit of k
    map<int, vector<int> > v;
    for (const pair<int, int>& i : m)
    {
        v[i.first >> (h + 1)].push_back(i.first);
    }
    vector<int> ans;
    for (const pair<int, vector<int> >& i : v)
    {
        vector<int> v0, v1;
        for (int j : i.second)
        {
            if (j & (1 << h)) v1.push_back(j);
            else v0.push_back(j);
        }
        vector<int> mx = maxi(h - 1, v0, v1);
        if (mx.empty()) mx = { i.second[0] };
        for (int j : mx) ans.push_back(m[j] + 1);
    }
    if (ans.size() < 2)
    {
        cout << "-1\n";
    }
    else
    {
        cout << ans.size() << "\n";
        for (int i : ans) cout << i << " ";
        cout << "\n";
    }
    return 0;
}