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
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long LL;
typedef pair<int, int> PII;

struct item {
    int prior, cnt, curCnt;
    char value;
    int l, r;
};

item nodes[2000005];
int ncnt = 0;

int cnt(int it) {
    return (it > -1) ? nodes[it].cnt : 0;
}

void updCnt(int it) {
    if (it > -1) nodes[it].cnt = cnt(nodes[it].l) + cnt(nodes[it].r) + nodes[it].curCnt;
}

void merge(int &t, int l, int r) {
    if (l == -1 || r == -1)
        t = (l > -1) ? l : r;
    else if (nodes[l].prior > nodes[r].prior)
        merge(nodes[l].r, nodes[l].r, r), t = l;
    else
        merge(nodes[r].l, l, nodes[r].l), t = r;
    updCnt(t);
}

int remL, remR;
char remC;
void erase(int &t, int key, int add = 0) {
    if (t == -1) return;
    int cur = add + cnt(nodes[t].l);
    if (key < cur)
        erase(nodes[t].l, key, add), updCnt(t);
    else if (key >= cur + nodes[t].curCnt)
        erase(nodes[t].r, key, cur + nodes[t].curCnt), updCnt(t);
    else {
        remL = cur;
        remR = cur + nodes[t].curCnt - 1;
        remC = nodes[t].value;
        merge(t, nodes[t].l, nodes[t].r);
    }
}

void split(int t, int &l, int &r, int key, int add = 0) {
    if (t == -1) {
        l = r = -1;
        return;
    }
    int cur = add + nodes[t].curCnt + cnt(nodes[t].l);
    if (key < cur - 1)
        split(nodes[t].l, l, nodes[t].l, key, add), r = t;
    else
        split(nodes[t].r, nodes[t].r, r, key, cur), l = t;
    updCnt(t);
}

void output(int t) {
    if (t == -1) return;
    output(nodes[t].l);
    REP(i, nodes[t].curCnt) putchar(nodes[t].value);
    output(nodes[t].r);
}

int pri[2000000], ppos = 0;

inline int getPri() {
    return pri[ppos++];
}

int newItem(char value, int cnt) {
    int ret = ncnt++;
    nodes[ret].prior = getPri();
    nodes[ret].cnt = nodes[ret].curCnt = cnt;
    nodes[ret].value = value;
    nodes[ret].l = nodes[ret].r = -1;
    return ret;
}

typedef unsigned long long ULL;
ULL MUL = 6364136223846793005ll;
ULL ADD = 1442695040888963407ll;
ULL randSeed = 1234567;

int myRand(int bound) {
    randSeed = MUL * randSeed + ADD;
    return (randSeed >> 32) % bound;
}

int n, q, treap;
char s[100005];
int rcnt[26];

int main() {
    REP(i, 2000000) pri[i] = i;
    random_shuffle(pri, pri + 2000000, myRand);
    scanf("%d%d", &n, &q);
    scanf("%s", s);
    for (int beg = 0; beg < n; ) {
        int end = beg + 1;
        while (end < n && s[end] == s[beg]) ++end;
        if (beg == 0) treap = newItem(s[beg], end - beg);
        else {
            int tmp = treap;
            merge(treap, tmp, newItem(s[beg], end - beg));
        }
        beg = end;
    }
    REP(z, q) {
        int from, to, k;
        scanf("%d%d%d", &from, &to, &k), --from, --to;
        REP(i, 26) rcnt[i] = 0;
        char putBackC = 'a', putBackCL = 'a';
        int putBackCnt = 0, putBackCntL = 0;
        while (from <= to) {
            erase(treap, from);
            assert(remL <= from && from <= remR);
            if (remR > to) putBackCnt = remR - to, putBackC = remC;
            if (remL < from) putBackCntL = from - remL, putBackCL = remC;
            int remCnt = min(remR, to) - max(remL, from) + 1;
            rcnt[remC - 'a'] += remCnt;
            to -= remCnt;
            if (remL < from) from -= putBackCntL, to -= putBackCntL;
        }
        int newTreap = -1;
        if (putBackCntL > 0) newTreap = newItem(putBackCL, putBackCntL);
        if (k == 1) {
            REP(i, 26) if (rcnt[i] > 0) {
                int tmp = newTreap;
                merge(newTreap, tmp, newItem('a' + i, rcnt[i]));
            }
        } else {
            for (int i = 25; i >= 0; --i) if (rcnt[i] > 0) {
                int tmp = newTreap;
                merge(newTreap, tmp, newItem('a' + i, rcnt[i]));
            }
        }
        if (putBackCnt > 0) {
            int tmp = newTreap;
            merge(newTreap, tmp, newItem(putBackC, putBackCnt));
        }
        int l, r, tmp;
        split(treap, l, r, from - 1);
        merge(tmp, l, newTreap);
        merge(treap, tmp, r);
    }
    output(treap);
    cout << endl;
    return 0;
}