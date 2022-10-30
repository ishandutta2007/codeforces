#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <string>
#include <list>
#include <stack>
#include <functional>

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

const int inf = int (1e9) + 7;

int main ()
{
    int n, m;

    cin >> n >> m;

    vector<pair<int, int>> arr (m);

    for (auto &it : arr)
    {
        scanf ("%i%i", &it.first, &it.second);
        it.first--;
        it.second--;
    }

    vector<int> par (n);

    for (int i = 0; i < par.size (); i++)
        par[i] = i;

    for (auto it : arr)
    {
        par[it.first] = min (par[it.first], it.second);
        par[it.second] = min (it.first, par[it.second]);
    }

    for (auto it : arr)
        if (par[it.first] != par[it.second])
        {
            cout << "NO" << endl;

            return 0;
        }

    vector<vector<int>> types (n);

    for (int i = 0; i < par.size (); i++)
        types[par[i]].push_back (i);

    unordered_set<long long> gr;
    gr.reserve (arr.size ());

    for (auto it : arr)
    {
        long long a = min (it.first, it.second), b  = max (it.first, it.second);

        gr.insert ((a << 32) | b);
    }

    for (const auto &cl : types)
        for (int i = 0; i < cl.size (); i++)
            for (int j = i + 1; j < cl.size (); j++)
                if (gr.find ((((long long)cl[i]) << 32) | cl[j]) == gr.end ())
                {
                    cout << "NO" << endl;

                    return 0;
                }

    cout << "YES" << endl;

    return 0;
}