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

int n, m;
string s;
map<string, int> pos;
set<pair<int, string> > q;

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
    while (n--)
    {
        cin >> s;
        if (pos.count(s))
            q.erase(mp(pos[s], s));
        pos[s] = m--;
        q.insert(mp(pos[s], s));
    }
    for (auto pr : q)
        cout << pr.second << '\n';

    return 0;
}