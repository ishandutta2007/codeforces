#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <list>
#include <stack>
#include <queue>

#include <cmath>
#include <cstdio>
#include <ctime>
#include <cassert>

using namespace std;

const int inf = int (1e9) + 7;

void Dijkstra (const vector<vector<int>> &arr, const vector<int> &me, vector<long long> &dist)
{
    vector<bool> used (arr.size ());

    for (int i = 0; i < used.size (); i++)
        used[i] = !me[i];

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;

    for (int i = 0; i < me.size (); i++)
        q.push ({2 * me[i], i});

    for (int i = 0; i < me.size (); i++)
        if (me[i] == 0)
            for (int j = 0; j < arr.size (); j++)
                q.push ({arr[i][j], j});

    while (!q.empty ())
    {
        auto it = q.top ();
        q.pop ();

        if (!used[it.second])
        {
            used[it.second] = true;

            dist[it.second] = it.first;

            for (int i = 0; i < arr[it.second].size (); i++)
                if (!used[i])
                    q.push ({it.first + arr[it.second][i], i});
        }
    }
}

int main ()
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);

    int n;

    cin >> n;

    vector<long long> al (n);

    for (auto &it : al)
        cin >> it;

    unordered_map<long long, int> cnt;
    cnt.reserve (n);

    for (auto it : al)
        cnt[it]++;

    int x = cnt[1];

    vector<int> len;
    len.reserve (n);

    while (cnt[1] > 0)
    {
        int l = 0;

        while (cnt[1ll << l] > 0)
            cnt[1ll << l++]--;

        len.push_back (l);
    }

    int used = 0;

    for (auto it = al.rbegin (); it != al.rend (); ++it)
    {
        if (cnt[*it] > 0)
        {
            cnt[*it]--;

            if (used < len.size () && *it < (1ll << len[used]))
                used++;
            else
            {
                cout << -1 << endl;

                return 0;
            }
        }
    }

    while (used + len.back () < len.size ())
    {
        used += len.back ();
        len.pop_back ();
    }

    for (int i = len.size (); i <= x; i++)
        cout << i << ' ';
    if (x < len.size ()) // shouldn't trigger
        cout << -1;
    cout << endl;

    return 0;
}