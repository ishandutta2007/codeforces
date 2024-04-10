#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool can(int a, int b, int c, int d)
{
    return ((c < a) && (a < d)) || ((c < b) && (b < d));
}

int main()
{
    int n; cin >> n;
    vector < pair<int,int> > v;

    for (int i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        if (a == 1) v.push_back(make_pair(b, c));
        if (a == 2)
        {
            queue <int> q;
            vector <bool> used(v.size());
            q.push(b - 1);
            used[b - 1] = true;
            while (!q.empty())
            {
                int cur = q.front();
                q.pop();
                for (int j = 0; j < v.size(); j++)
                {
                    if (used[j]) continue;
                    if (!can(v[cur].first, v[cur].second, v[j].first, v[j].second)) continue;
                    q.push(j);
                    used[j] = true;
                }
            }
            if (used[c - 1]) cout << "YES" << endl; else cout << "NO" << endl;
        }
    }
}