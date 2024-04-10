#include <cstdio>
#include <map>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 100000;

struct TNode {
    int suf;
    int len;
    int sufst;

    TNode()
        : suf(-1)
        , len(0)
        , sufst(0)
    {
    }
};

TNode st[3 * MAXN];
map<char, int> linx[3 * MAXN];
int cnt[3 * MAXN];
int stsize = 0;

int newNode() {
    st[stsize] = TNode();
    linx[stsize].clear();
    return stsize++;
}

int append(int end, char c) {
    int newEnd = newNode();
    st[newEnd] = TNode();
    cnt[newEnd] = 1;
    linx[end][c] = newEnd;
    st[newEnd].len = st[end].len + 1;
    st[newEnd].sufst = 0;
    int cur = st[end].suf;
    while (cur >= 0 && !linx[cur].count(c)) {
        linx[cur][c] = newEnd;
        cur = st[cur].suf;
    }
    if (cur < 0) {
        st[newEnd].suf = 0;
        return newEnd;
    }
    int q = linx[cur][c];
    if (st[q].len - st[cur].len == 1) {
        st[newEnd].suf = q;
        return newEnd;
    }
    int clone = newNode();
    st[clone] = st[q];
    linx[clone] = linx[q];
    st[clone].len = st[cur].len + 1;
    st[clone].sufst = st[newEnd].len - st[clone].len;

    st[newEnd].suf = clone;
    st[q].suf = clone;
    while (cur >= 0 && linx[cur].count(c) && linx[cur][c] == q) {
        linx[cur][c] = clone;
        cur = st[cur].suf;
    }
    return newEnd;
}

bool isSubstr(int start, char *s) {
    for (int i = 0; s[i]; ++i) {
        if (!linx[start].count(s[i])) {
            return false;
        }
        start = linx[start][s[i]];
    }
    return true;
}

char s[200000];

int main() {
    scanf("%s", s);
    int end = newNode();
    for (int i = 0; s[i]; ++i) {
        end = append(end, s[i]);
    }
    vector<pair<int, int> > ord;
    for (int i = 0; i < stsize; ++i) {
        ord.push_back(make_pair(st[i].len, i));
    }
    sort(ord.rbegin(), ord.rend());
    for (int i = 0; i < stsize; ++i) {
        int q = ord[i].second;
        cnt[st[q].suf] += cnt[q];
    }
    long long ans = 0;
/*    for (int i = 0; i < stsize; ++i) {
        cerr << i << ' ' << string(s + st[i].sufst, s + st[i].sufst + st[i].len) << ' ' << st[i].suf << ' ' << count[i] << '\n';
    }*/
//    cerr << '\n';
    for (int i = 1; i < stsize; ++i) {
        int q = st[i].len - st[st[i].suf].len;
        ans += 1LL * q * cnt[i] * (cnt[i] + 1) / 2;
    }
    cout << ans << '\n';

    return 0;
}