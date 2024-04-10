#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <ctime>
#include <random>
#include <cmath>
#include <bitset>
#include <iomanip>
#include <list>

using namespace std;

typedef long long ll;

struct node {
    int cnt;
    int next0, next1;
    node() {
        cnt = 0;
        next0 = -1;
        next1 = -1;
    }
};

vector <node> t;

int uk = 0;

vector <ll> ans;

void add(string &s) {
    int cur = 0;
    ++t[cur].cnt;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '0') {
            if (t[cur].next0 == -1) {
                t[cur].next0 = ++uk;
                t.push_back(node());
            }
            cur = t[cur].next0;
            ++t[cur].cnt;
        }
        else {
            if (t[cur].next1 == -1) {
                t[cur].next1 = ++uk;
                t.push_back(node());
            }
            cur = t[cur].next1;
            ++t[cur].cnt;
        }
    
    }
}

string convert(ll x) {
    string res;
    for (int i = 0; i < 60; ++i) {
        if (x & (1ll << i)) res += '1';
        else res += '0';
    }
    reverse(res.begin(), res.end());
    return res;
}

ll convert_back(string s) {
    reverse(s.begin(), s.end());
    ll res = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '1') res += (1ll << i);
    }
    return res;
}

void bye() {
    cout << "No\n";
    exit(0);
}

bool dfs(int cur, bool done, int len, string &scur, string &s) {
    if (cur == -1) return 0;
    --t[cur].cnt;
    if (t[cur].cnt < 0) {
        ++t[cur].cnt;
        return 0;
    }
    if (len == 60 && done) {
        ans.push_back(convert_back(scur));
        return 1;
    }
    if (done) {
        if (s[len] == '0') {
            scur += '0';
            if (dfs(t[cur].next0, 1, len + 1, scur, s)) {
                scur.pop_back();
                return 1;
            }
            scur.pop_back();
            scur += '1';
            if (dfs(t[cur].next1, 1, len + 1, scur, s)) {
                scur.pop_back();
                return 1;
            }
            scur.pop_back();
            ++t[cur].cnt;
            return 0;
        }
        else {
            scur += '1';
            if (dfs(t[cur].next1, 1, len + 1, scur, s)) {
                scur.pop_back();
                return 1;
            }
            scur.pop_back();
            scur += '0';
            if (dfs(t[cur].next0, 1, len + 1, scur, s)) {
                scur.pop_back();
                return 1;
            }
            scur.pop_back();
            ++t[cur].cnt;
            return 0;
        }
    }
    else {
        if (s[len] == '1') {
            scur += '0';
            if (dfs(t[cur].next0, 0, len + 1, scur, s)) {
                scur.pop_back();
                return 1;
            }
            else {
                scur.pop_back();
                ++t[cur].cnt;
                return 0;
            }
        }
        else {
            scur += '0';
            if (dfs(t[cur].next0, 0, len + 1, scur, s)) {
                scur.pop_back();
                return 1;
            }
            else {
                scur.pop_back();
            }
            scur += '1';
            if (dfs(t[cur].next1, 1, len + 1, scur, s)) {
                scur.pop_back();
                return 1;
            }
            else {
                scur.pop_back();
            }
            ++t[cur].cnt;
            return 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    t.resize(1);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        string s = convert(x);
        add(s);
    }
    string tmp;
    string cur = string(60, '0');
    for (int i = 0; i < n; ++i) {
        if (!dfs(0, 0, 0, tmp, cur)) bye();
        cur = convert(ans.back() ^ convert_back(cur));
    }
    cout << "Yes\n";
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << ' ';
    }
}