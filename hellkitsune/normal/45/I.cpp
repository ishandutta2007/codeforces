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
vector<int> neg, pos;
int z = 0;
vector<int> ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    REP(i, n) {
        int x;
        cin >> x;
        if (x < 0) neg.pb(x);
        else if (x > 0) pos.pb(x);
        else ++z;
    }
    sort(neg.begin(), neg.end());
    if (pos.empty() && (int)neg.size() < 2) {
        if (z > 0) {
            cout << 0 << endl;
        } else {
            cout << neg.back() << endl;
        }
        return 0;
    }
    for (int x : pos) ans.pb(x);
    for (int i = 0; i + 1 < (int)neg.size(); i += 2) {
        ans.pb(neg[i]);
        ans.pb(neg[i + 1]);
    }
    for (int x : ans) cout << x << ' ';
    cout << endl;
    return 0;
}