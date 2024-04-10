#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
vector <int> d, a;

bool check(int q)
{
    vector < pair <int, int> > last(m);
    for (int i = 0; i < m; i++) last[i].second = i;
    for (int i = 0; i < q; i++)
        if (d[i] != 0) last[d[i]-1].first = i;
    sort(last.begin(), last.end());
    int prp = 0;
    for (int i = 0; i < m; i++)
    {
        if (prp + a[last[i].second] > last[i].first) return false;
        prp += a[last[i].second] + 1;
    }
    return true;
}

int binsearch(int l, int r)
{
    while (l < r)
    {
        int m = (l + r) / 2;
        if (check(m)) r = m; else l = m+1;
    }
    return l;
}

int main()
{
    cin >> n >> m;
    d.resize(n), a.resize(m);
    for (int i = 0; i < n; i++) cin >> d[i];
    for (int j = 0; j < m; j++) cin >> a[j];
    int ans = binsearch(1, n);
    if (!check(n)) ans = -1;
    cout << ans << endl;
}