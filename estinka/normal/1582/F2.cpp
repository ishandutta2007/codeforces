#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;

const int maxa = 1 << 13;
vector<vector<int> > v(maxa);
int x[maxa], x2[maxa];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i], v[a[i]].push_back(i);
    fill(x, x + maxa, n);
    x[0] = -1;
    for (int i = 0; i < maxa; i++) if (v.size())
    {
        fill(x2, x2 + maxa, n);
        for (int j = 0; j < maxa; j++) if (x[j] != n)
        {
            int l = upper_bound(v[i].begin(), v[i].end(), x[j]) - v[i].begin();
            if (l != v[i].size()) x2[j ^ i] = v[i][l];
        }
        for (int j = 0; j < maxa; j++) x[j] = min(x2[j], x[j]);
    }
    vector<int> b;
    for (int i = 0; i < maxa; i++) if (x[i] < n) b.push_back(i);
    cout << b.size() << "\n";
    for (int i : b) cout << i << " ";
    cout << "\n";
    return 0;
}