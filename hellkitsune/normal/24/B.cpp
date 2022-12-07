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

int t, n;
map<string, int> ma;
string rev[100];
int mac = 0;
const int a[10] = {25, 18, 15, 12, 10, 8, 6, 4, 2, 1};
int cnt[100][50] = {}, score[100] = {};
int ord[100];

bool cmp1(const int &lhs, const int &rhs) {
    if (score[lhs] == score[rhs]) {
        REP(i, 50) if (cnt[lhs][i] != cnt[rhs][i])
            return cnt[lhs][i] > cnt[rhs][i];
        return false;
    }
    return score[lhs] > score[rhs];
}

bool cmp2(const int &lhs, const int &rhs) {
    if (cnt[lhs][0] != cnt[rhs][0])
        return cnt[lhs][0] > cnt[rhs][0];
    if (score[lhs] != score[rhs])
        return score[lhs] > score[rhs];
    for (int i = 1; i < 50; ++i) if (cnt[lhs][i] != cnt[rhs][i])
        return cnt[lhs][i] > cnt[rhs][i];
    return false;
}

int mapGet(string &s) {
    auto it = ma.find(s);
    if (it == ma.end()) {
        rev[mac] = s;
        ma[s] = mac;
        return mac++;
    }
    return it->second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> t;
    REP(race, t) {
        cin >> n;
        REP(i, n) {
            string s;
            cin >> s;
            int cur = mapGet(s);
            if (i < 10) {
                score[cur] += a[i];
            }
            ++cnt[cur][i];
        }
    }
    REP(i, mac) ord[i] = i;
    sort(ord, ord + mac, cmp1);
    cout << rev[ord[0]] << endl;
    sort(ord, ord + mac, cmp2);
    cout << rev[ord[0]] << endl;
    return 0;
}