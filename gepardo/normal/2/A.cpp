#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    int n; cin >> n;
    vector <string> s(n);
    vector <int> v(n);
    vector <int> q(n);
    vector <string> u;

    string qqq; getline(cin, qqq);
    for (int i = 0; i < n; i++)
    {
        string q; getline(cin, q);
        int vv = q.find(" ");
        s[i] = q.substr(0, vv);
        q.erase(0, vv + 1);
        istringstream is(q);
        is >> v[i];
    }
    for (int i = 0; i < n; i++)
    {
        q[i] = -1;
        for (int j = 0; j < u.size(); j++)
            if (s[i] == u[j])
            {
                q[i] = j;
                break;
            }
        if (q[i] < 0)
        {
            q[i] = u.size();
            u.push_back(s[i]);
        }
    }
    int k = u.size();

    vector <int> p(k);

    for (int i = 0; i < n; i++)
        p[q[i]] += v[i];

    int mx = -123456789;
    for (int i = 0; i < k; i++) mx = max(mx, p[i]);

    vector<int> p2(k);
    for (int i = 0; i < n; i++)
    {
        p2[q[i]] += v[i];
        if (p2[q[i]] >= mx && p[q[i]] == mx)
        {
            cout << u[q[i]];
            break;
        }
    }
}