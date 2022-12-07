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

const int T = 1440;
int m, n, k;
map<string, int> ma;
string s[100];
bool f[T * 30 + 3];
int sum[T * 30 + 3];
int taskT[100], taskDL[100], taskRew[100];
int d[T * 30 + 3][101] = {}, p[T * 30 + 3][101];
vector<string> ans;
int ord[100];

int strToTime(int d, string s) {
    --d;
    int t = ((s[0] - '0') * 10 + s[1] - '0') * 60 + (s[3] - '0') * 10 + s[4] - '0';
    t += d * T;
    return t;
}

string timeToStr(int t) {
    ostringstream oss;
    oss << t / T + 1 << ' ';
    t %= T;
    oss << t / 600;
    t %= 600;
    oss << t / 60 << ':';
    t %= 60;
    oss << t / 10;
    t %= 10;
    oss << t;
    return oss.str();
}

bool cmp(const int &lhs, const int &rhs) {
    return taskDL[lhs] < taskDL[rhs];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> m >> n >> k;
    REP(i, m) cin >> s[i];
    REP(i, m) {
        int t;
        cin >> t;
        ma[s[i]] = t;
    }
    REP(i, T) f[i] = true;
    REP(i, 4) {
        string s;
        cin >> s;
        int from = ((s[0] - '0') * 10 + s[1] - '0') * 60 + (s[3] - '0') * 10 + s[4] - '0';
        int to = ((s[6] - '0') * 10 + s[7] - '0') * 60 + (s[9] - '0') * 10 + s[10] - '0';
        for (int j = from; j <= to; ++j) {
            f[j] = false;
        }
    }
    for (int i = 1; i < k; ++i) {
        int dif = i * T;
        REP(j, T) f[j + dif] = f[j];
    }
    sum[0] = 0;
    REP(i, k * T) sum[i + 1] = sum[i] + f[i];
    REP(i, n) {
        string s;
        cin >> s;
        auto it = ma.find(s);
        if (it == ma.end()) {
            taskT[i] = 100000;
        } else {
            taskT[i] = it->second;
        }
        int td;
        cin >> td >> s;
        taskDL[i] = strToTime(td, s);
        cin >> taskRew[i];
    }
    REP(i, n) ord[i] = i;
    sort(ord, ord + n, cmp);
    REP(i, k * T) REP(j, n) if (i == 0 || d[i][j] != 0) {
        int ind = ord[j];
        int lo = i, hi = taskDL[ind], mid;
        while (lo < hi) {
            mid = (lo + hi) >> 1;
            if (sum[mid + 1] - sum[i] < taskT[ind])
                lo = mid + 1;
            else
                hi = mid;
        }
        if (d[i][j + 1] < d[i][j]) {
            d[i][j + 1] = d[i][j];
            p[i][j + 1] = i;
        }
        if (lo < taskDL[ind] && d[lo + 1][j + 1] < d[i][j] + taskRew[ind]) {
            d[lo + 1][j + 1] = d[i][j] + taskRew[ind];
            p[lo + 1][j + 1] = i;
        }
    }
    int best = 0, ii = 0, jj = 0;
    REP(i, k * T + 1) REP(j, n + 1) if (d[i][j] > best) {
        best = d[i][j];
        ii = i;
        jj = j;
    }
    while (jj) {
        if (p[ii][jj] != ii) {
            ostringstream oss;
            oss << ord[jj - 1] + 1 << ' ';
            int begTime = p[ii][jj];
            while (!f[begTime]) ++begTime;
            oss << timeToStr(begTime) << ' ';
            oss << timeToStr(ii - 1);
            ans.pb(oss.str());
        }
        ii = p[ii][jj];
        --jj;
    }
    reverse(ans.begin(), ans.end());
    cout << best << '\n' << (int)ans.size() << '\n';
    for (string s : ans) cout << s << '\n';
    return 0;
}