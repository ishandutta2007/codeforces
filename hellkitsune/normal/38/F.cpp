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
map<string, int> ma;
int mac = 0;
int mx[20000], sum[20000], cnt[20000], w[20000], a[20000], b[20000];
string rev[20000];

void putHash(string s) {
    auto it = ma.find(s);
    if (it == ma.end()) {
        mx[mac] = sum[mac] = 0;
        for (char c : s) {
            mx[mac] = max(mx[mac], c - 'a' + 1);
            sum[mac] += c - 'a' + 1;
        }
        cnt[mac] = 1;
        ma[s] = mac;
        rev[mac] = s;
        ++mac;
        return;
    }
    ++cnt[it->second];
}

int getHash(string s) {
    auto it = ma.find(s);
    if (it == ma.end()) return -1;
    return it->second;
}

vector<string> v;

void calc(int ind) {
    string s = rev[ind];
    s += ' ';
    a[ind] = b[ind] = 0;
    w[ind] = -1;
    for (char c = 'a'; c <= 'z'; ++c) {
        s.back() = c;
        int h = getHash(s);
        if (h == -1) continue;
        if (w[h] == -1) calc(h);
        int curA = b[h] + sum[h] * mx[h] + cnt[h];
        int curB = a[h];
        int curW = 1 - w[h];
        if (curW > w[ind] ||
            (curW == w[ind] && (curA > a[ind] ||
            (curA == a[ind] && curB < b[ind])))) {
            w[ind] = curW;
            a[ind] = curA;
            b[ind] = curB;
        }
    }
    s = " ";
    s += rev[ind];
    for (char c = 'a'; c <= 'z'; ++c) {
        s[0] = c;
        int h = getHash(s);
        if (h == -1) continue;
        if (w[h] == -1) calc(h);
        int curA = b[h] + sum[h] * mx[h] + cnt[h];
        int curB = a[h];
        int curW = 1 - w[h];
        if (curW > w[ind] ||
            (curW == w[ind] && (curA > a[ind] ||
            (curA == a[ind] && curB < b[ind])))) {
            w[ind] = curW;
            a[ind] = curA;
            b[ind] = curB;
        }
    }
    if (w[ind] == -1) w[ind] = 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    string tmp;
    putHash(tmp);
    REP(z, n) {
        string s;
        cin >> s;
        REP(i, s.length()) for (int j = i; j < (int)s.length(); ++j) {
            v.pb(s.substr(i, j - i + 1));
        }
        sort(v.begin(), v.end());
        REP(i, v.size()) if (i == 0 || v[i] != v[i - 1]) {
            putHash(v[i]);
        }
        v.clear();
    }
    REP(i, mac) w[i] = -1;
    calc(0);
    if (w[0] == 0) printf("Second\n");
    else printf("First\n");
    printf("%d %d\n", a[0], b[0]);
    return 0;
}