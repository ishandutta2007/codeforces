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

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); e++)
typedef long long LL;
typedef pair<int, int> PII;

map<string, int> ma;
string re[50];
int n;
int score[50] = {}, goals[50] = {}, misses[50] = {};
int ord[50];

bool cmp(const int &lhs, const int &rhs) {
    if (score[lhs] == score[rhs]) {
        if (goals[lhs] - misses[lhs] == goals[rhs] - misses[rhs]) {
            return goals[lhs] > goals[rhs];
        }
        return goals[lhs] - misses[lhs] > goals[rhs] - misses[rhs];
    }
    return score[lhs] > score[rhs];
}

vector<string> ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    REP(i, n) {
        cin >> re[i];
        ma[re[i]] = i;
    }
    REP(i, (n * (n - 1)) / 2) {
        string s, t;
        cin >> s >> t;
        int fi, se;
        int pos = 0;
        while (s[pos] != '-') ++pos;
        fi = ma[s.substr(0, pos)];
        se = ma[s.substr(pos + 1)];
        REP(i, t.length()) if (t[i] == ':')
            t[i] = ' ';
        istringstream iss(t);
        int a, b;
        iss >> a >> b;
        if (a > b) score[fi] += 3;
        else if (a < b) score[se] += 3;
        else ++score[fi], ++score[se];
        goals[fi] += a;
        misses[se] += a;
        goals[se] += b;
        misses[fi] += b;
    }
    REP(i, n) ord[i] = i;
    sort(ord, ord + n, cmp);
    REP(i, n / 2) ans.pb(re[ord[i]]);
    sort(ans.begin(), ans.end());
    REP(i, n / 2)
        cout << ans[i] << endl;
    return 0;
}