#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> s(n), d(n);
    for (int i = 0 ; i < n; i++)
    {
        cin >> s[i] >> d[i];
    }
    set<int> interesting(s.begin(), s.end());
    interesting.insert(1);
    set<int> bad;
    for (int i = 0; i < n; i++)
    {
        auto it = interesting.lower_bound(s[i]);
        bool b = true;
        while (true)
        {
            assert(it != interesting.end());
            int p = *it;
            if (b)
            {
            	it = interesting.begin();
            	b = false;
            	if (p != s[i])
            	{
            		continue;
            	}
            }
            else
            {
            	++it;
            }
            auto closest = bad.lower_bound(p);
            if (closest != bad.end() && *closest - p < d[i])
            {
                continue;
            }
            int q = p + d[i] - 1;
            cout << p << ' ' << q << endl;
            bad.insert(p);
            bad.insert(q);
            while (true)
            {
                auto oit = interesting.lower_bound(p);
                if (oit == interesting.end() || *oit > q)
                {
                    break;
                }
                else
                {
                    interesting.erase(oit);
                }
            }
            interesting.insert(q + 1);
            break;
        }
    }
}