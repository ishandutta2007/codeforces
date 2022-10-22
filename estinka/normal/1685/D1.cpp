#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>
typedef long long ll;
typedef long double ld;
using namespace std;

vector<int> par;
int root(int a) { return par[a] == a ? a : a = root(par[a]); }
bool merge(int a, int b)
{
    a = root(a);
    b = root(b);
    if (a == b) return false;
    par[a] = b;
    return true;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> p(n), r(n);
    par.assign(n, 0);
    for (int i = 0; i < n; i++) par[i] = i;
    for (int i = 0; i < n; i++) cin >> p[i], p[i]--;
    r = p;
    for (int i = 0; i < n; i++)
    {
        merge(i, p[i]);
    }
    for (int x = 0; x + 1 < n; x++) 
    {
        int i = find(r.begin(), r.end(), x) - r.begin();
        for (int j = 0; j < n; j++) if (r[j] == x + 1 && merge(i, j))
        {
            swap(r[i], r[j]);
            break;
        }
    }
    vector<int> q;
    int i = 0;
    while (q.size() < n)
    {
        q.push_back(i);
        i = r[i];
    }
    reverse(q.begin(), q.end());
    int sum = 0;
    for (int i = 0; i < n; i++) sum += abs(q[i] - p[q[(i + 1) % n]]);
    //cout << "               " << sum << "\n";
    for (int i = 0; i < n; i++) cout << q[i] + 1 << " \n"[i == n - 1];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}