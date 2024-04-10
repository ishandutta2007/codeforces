#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    vector <int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i], v[i]--;
    vector <bool> ended(n, true), used(n);
    vector < pair<int,int> > comps;
    for (int i = 0; i < n; i++) ended[v[i]] = false;
    for (int i = 0; i < n; i++)
    {
        if ((!ended[i]) || used[i]) continue;
        int cur = i;
        while (!used[cur]) used[cur] = true, cur = v[cur];
        comps.push_back({i, cur});
    }

    vector < pair<int,int> > ans;

    if (comps.size() == 0)
    {
        int last = -1, first = -1;

        for (int i = 0; i < n; i++)
        {
            if (used[i]) continue;
            int cur = i;
            if (last == -1) last = first = i;
               else ans.push_back({last, i});
            last = i;
            while (!used[cur]) used[cur] = true, cur = v[cur];
        }
        if (first != last) ans.push_back({last, first});
    }
    else
    {
        for (int i = 1; i < comps.size(); i++)
            ans.push_back({comps[i - 1].second, comps[i].first});
        int last = comps[comps.size() - 1].second;
        for (int i = 0; i < n; i++)
        {
            if (used[i]) continue;
            int cur = i;
            ans.push_back({last, i});
            last = i;
            while (!used[cur]) used[cur] = true, cur = v[cur];
        }
        ans.push_back({last, comps[0].first});
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) cout << ans[i].first + 1 << " " << ans[i].second + 1 << endl;
}