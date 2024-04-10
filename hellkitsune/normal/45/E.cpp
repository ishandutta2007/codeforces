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
typedef long long LL;
typedef pair<int, int> PII;

int n;
string a[100], b[100];
bool used[100];
int cnt[26] = {}, cntA[26] = {};

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    REP(i, n) cin >> a[i];
    REP(i, n) cin >> b[i];
    REP(i, n) used[i] = false;
    REP(i, n) --cnt[a[i][0] - 'A'];
    REP(i, n) ++cnt[b[i][0] - 'A'];
    REP(i, 26) cntA[i] = -cnt[i];
    sort(a, a + n);
    sort(b, b + n);
    REP(i, n) {
        cout << a[i] << ' ';
        int best = -1;
        REP(j, n) if (!used[j]) {
            if (a[i][0] == b[j][0]) {
                best = j;
                break;
            }
            if (cnt[b[j][0] - 'A'] > 0 && cntA[a[i][0] - 'A'] > 0) {
                best = j;
                --cnt[b[j][0] - 'A'];
                --cntA[a[i][0] - 'A'];
                break;
            }
        }
        assert(best != -1);
        used[best] = true;
        cout << b[best];
        if (i == n - 1) cout << endl;
        else cout << ", ";
    }
    return 0;
}