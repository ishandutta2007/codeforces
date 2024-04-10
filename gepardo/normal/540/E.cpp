#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#define int long long

using namespace std;

const int maxN = 200000;

class fenwick
{
    private:
        vector <long long> v;
        int n;
    public:
        fenwick(int n) : v(n), n(n) {}
        int size() { return n; }
        void modify(int i, long long delta)
        {
            for (; i < n; i |= i + 1) v[i] += delta;
        }
        int sum(long long i)
        {
            long long res = 0;
            for (; i >= 0; i &= i + 1, i--) res += v[i];
            return res;
        }
};

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int m; cin >> m;
    int n;
    vector < pair<int,int> > v(m);
    vector <int> q;
    for (int i = 0; i < m; i++)
    {
        int a, b; cin >> a >> b;
        v[i] = {a, b};
        q.push_back(a);
        q.push_back(b);
    }
    sort(q.begin(), q.end());

    vector < pair<int, int> > nr;
    map <int,int> mp;

    if (q[0] != 1) nr.push_back({nr.size(), q[0] - 1});
    mp[q[0]] = nr.size(), nr.push_back({nr.size(), 1});

    for (int i = 1; i < q.size(); i++)
    {
        if (q[i] == q[i - 1]) continue;
        if (q[i] - q[i - 1] != 1) nr.push_back({nr.size(), q[i] - q[i - 1] - 1});
        mp[q[i]] = nr.size(), nr.push_back({nr.size(), 1});
    }
/*
    cout << "here, hare :) " << " " << nr.size() << endl;
    for (auto it: mp) cout << "{" << it.first << ", " << it.second << "} "; cout << endl;
*/
    for (int i = 0; i < m; i++) swap(nr[mp[v[i].first]], nr[mp[v[i].second]]);
/*
    for (auto it: nr) cout << "{" << it.first << ", " << it.second << "} "; cout << endl;
*/
    n = nr.size();

    long long ans = 0;
    fenwick f(n);
    for (int i = n - 1; i >= 0; i--)
    {
        ans += f.sum(nr[i].first) * nr[i].second;
        f.modify(nr[i].first, nr[i].second);
    }
    cout << ans;
}