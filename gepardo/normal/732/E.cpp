#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int n, m; cin >> n >> m;
    vector <int> p(n);
    vector <int> s(m);
    for (int i = 0; i < n; i++) cin >> p[i];
    for (int i = 0; i < m; i++) cin >> s[i];

    unordered_map <int, vector <int> > q;
    vector < pair <int, int> > w;
    w.reserve(m);
    for (int i = 0; i < n; i++) q[p[i]].push_back(i);
    for (int i = 0; i < m; i++) w.push_back({s[i], i});
    sort(w.begin(), w.end());

    int c = 0, u = 0;
    vector <int> a(m);
    vector <int> b(n);
    for (int i = 0; i < m; i++)
    {
        int cto = w[i].second, val = w[i].first;
        int ctr = 0;
        while (val)
        {
            if (q.count(val))
            {
                vector <int> &qval = q[val];
                if (!qval.empty())
                {
                    c++; u += ctr;
                    a[cto] = ctr;
                    b[qval.back()] = cto+1;
                    qval.pop_back();
                    break;
                }
            }
            val = (val == 1) ? 0 : ((val + 1) / 2);
            ctr++;
        }
    }

    cout << c << " " << u << endl;
    for (int i = 0; i < m; i++) cout << a[i] << " "; cout << endl;
    for (int i = 0; i < n; i++) cout << b[i] << " "; cout << endl;
    return 0;
}