#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <map>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <cassert>
#include <string>
#include <cstring>

#define fs first
#define sc second
#define mp make_pair
#define pb push_back

#ifdef DEBUG
#define dout(x) cerr << x
#else
#define dout(x)
#endif

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 1e9+100;
const ll lINF = 1e18;
const double E = 2.718281828459045;

int n, m, ans, used[3333];
vector<int> g[3333], gr[3333];

int main()
{
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].pb(b);
        gr[b].pb(a);
    }
    for (int i = 0; i < n; i++) {
        sort(g[i].begin(), g[i].end());
        sort(gr[i].begin(), gr[i].end());
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i!= j) {
                int cnt = 0;
                for (int k = 0; k < g[i].size(); k++) {
                    used[g[i][k]]=1;
                }
                for (int k = 0; k < gr[j].size(); k++) {
                    if (used[gr[j][k]]) cnt++;
                }
                for (int k = 0; k < g[i].size(); k++) {
                    used[g[i][k]]=0;
                }
                ans += cnt*(cnt-1)/2;
            }
        }
    }
    cout << ans << endl;
    return 0;
}