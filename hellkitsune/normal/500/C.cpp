#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <cassert>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); ++e)
typedef long long LL;
typedef pair<int, int> PII;

int n, m;
int w[1000], b[1000];
int st[1000], sts = 0;
bool used[1000] = {};

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    REP(i, n) cin >> w[i];
    REP(i, m) cin >> b[i], --b[i];
    REP(i, m) if (!used[b[i]])
        st[sts++] = b[i], used[b[i]] = true;
    REP(i, n) if (!used[i])
        st[sts++] = i;
    int ans = 0;
    REP(i, m) {
        int ind = 0;
        while (st[ind] != b[i])
            ans += w[st[ind]], ++ind;
        for (int j = ind; j > 0; --j)
            st[j] = st[j - 1];
        st[0] = b[i];
    }
    cout << ans << endl;
    return 0;
}