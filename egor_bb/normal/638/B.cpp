#include <bits/stdc++.h>

#define MOD (1000000007)
#define EPS (1e-9)
#define INF (2117117117)
#define LLINF (2117117117117117117LL)
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define sqr(a) ((a) * (a))
#define sz(a) ((int) (a).size())
const double PI = acos(-1.0);

typedef unsigned int uint;
typedef long long llong;
typedef long double ldouble;
typedef unsigned long long ullong;

#define TASK "task"

using namespace std;

int n;
vector<string> a;

int main()
{
#ifdef lordf
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    //freopen(TASK".in", "r", stdin);
    //freopen(TASK".out", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; cin >> a[i++]);
    for (;;)
    {
        bool f = false;
        for (int i = 0; !f && i < sz(a); i++)
            for (int j = i + 1; !f && j < sz(a); j++)
            {
                string s = a[i], t = a[j];
                size_t k;
                f = true;
                if (s.find(t) != string::npos)
                    a.erase(find(a.begin(), a.end(), t));
                else if (t.find(s) != string::npos)
                    a.erase(find(a.begin(), a.end(), s));
                else if ((k = s.find(t[0])) != string::npos)
                {
                    a.erase(find(a.begin(), a.end(), s));
                    a.erase(find(a.begin(), a.end(), t));
                    a.push_back(s + t.substr(sz(s) - k));
                }
                else if ((k = t.find(s[0])) != string::npos)
                {
                    a.erase(find(a.begin(), a.end(), s));
                    a.erase(find(a.begin(), a.end(), t));
                    a.push_back(t + s.substr(sz(t) - k));
                }
                else
                    f = false;
            }
        if (!f)
            break;
    }
    for (auto s : a)
        cout << s;
    cout << '\n';

    return 0;
}