#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <cassert>
#include <cstdlib>

#define mp make_pair
#define fs first
#define sc second
#define pb push_back

typedef long long ll;
typedef long double ld;

const ll INF = 1e9;
const ll lINF = 1e18;

#ifdef DEBUG
#define dout(x) cerr<<x;
#else
#define dout(x)
#endif

using namespace std;

int n, p[333], ans[333];
int g[333][333];
int used[333];

vector<int> vec, v2;

void dfs(int v) {
    if (used[v]) {
        return;
    }
    used[v] = true;
    vec.push_back(p[v]);
    v2.pb(v);
    for (int i = 0; i < n; i++) {
        if (g[v][i]) dfs(i);
    }
}

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            if (s[j] == '1') {
                g[i][j] = 1;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            dfs(i);
            sort(vec.begin(), vec.end());
            sort(v2.begin(), v2.end());
            for (int i = 0; i < vec.size(); i++) {
                ans[v2[i]] = vec[i];
            }
            vec.clear();
            v2.clear();
        }
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i]  << ' ';
    }
    return 0;
}