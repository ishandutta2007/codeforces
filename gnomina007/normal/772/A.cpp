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

template<class K, class M>
bool divcomp (const pair<K, K> &a, const pair<M, M> &b)
{
    return a.first * (long long)b.second > b.first * (long long)a.second;
}

int main ()
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);

    int n, p;

    cin >> n >> p;

    vector<pair<int, int>> dev (n);

    for (auto &it : dev)
        cin >> it.first >> it.second;

    long long sa = -p, sb = 0;

    for (const auto &it : dev)
    {
        sa += it.first;
        sb += it.second;
    }

    if (sa <= 0)
    {
        cout << -1 << endl;

        return 0;
    }

    sort (dev.begin (), dev.end (), divcomp<int, int>);

    while (divcomp<long long, int> ({sa, sb}, dev.back ()))
    {
        sa -= dev.back ().first;
        sb -= dev.back ().second;

        dev.pop_back ();
    }

    cout.precision (10);
    cout << fixed << sb / (double)sa << endl;

    return 0;
}