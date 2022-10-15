#include <iostream>
#include <vector>
#include <algorithm>
#define ff first
#define ss second

using namespace std;

int main()
{
    int n, m; cin >> n >> m;
    vector <int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector < pair<int, int> > b(m);
    for (int i = 0; i < m; i++) cin >> b[i].ff >> b[i].ss;

    vector <int> ans(n);
    vector <int> q, w;

    vector <int> suf(m);
    suf[m - 1] = m - 1;
    for (int i = m - 2; i >= 0; i--)
        if (b[suf[i + 1]].ss <= b[i].ss) suf[i] = i;
            else suf[i] = suf[i + 1];

    for (int i = 0; i < m; i++)
        q.push_back(b[suf[i]].ss),
        w.push_back(b[suf[i]].ff - 1), i = suf[i];
    q.push_back(0);

    int l = 0, r = n-1, rev, lst = n-1;
    for (int i = q[0]; i < n; i++)
        ans[lst--] = a[r], r--;
    sort(a.begin(), a.begin() + lst + 1);
    for (int i = 0; i < (int)q.size() - 1; i++)
    {
        rev = w[i];
        for (int j = q[i + 1]; j < q[i]; j++)
            if (!rev)
                ans[lst--] = a[r], r--;
            else
                ans[lst--] = a[l], l++;
    }

    for (int i = 0; i < n; i++) cout << ans[i] << " ";
    cout << endl;

    return 0;
}