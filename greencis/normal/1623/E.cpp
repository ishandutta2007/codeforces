#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;
using pii = pair<int, int>;

string s;
int l[200200], r[200200];
int parent[200200];
int orderInDfs[200200];
string dfsString;
string nxtInDfs;
bool needDouble[200200];
bool marked[200200];
int k;

void buildStr(int v, bool checkDouble = false) {
    if (v < 0) return;
    buildStr(l[v], checkDouble);
    orderInDfs[v] = dfsString.size();
    dfsString.push_back(s[v]);
    if (checkDouble && needDouble[v])
        dfsString.push_back(s[v]);
    buildStr(r[v], checkDouble);
}

void dfsSolve(int v, int need = 1) {
    if (v < 0) return;
    if (needDouble[v])
        need = 0;
    dfsSolve(l[v], need + 1);
    if (!needDouble[v] && need <= k && s[v] < nxtInDfs[orderInDfs[v]]) {
        k -= need;
        int cur = v;
        while (cur >= 0 && !needDouble[cur]) {
            needDouble[cur] = true;
            cur = parent[cur];
        }
    }
    if (needDouble[v]) {
        need = 0;
        dfsSolve(r[v], need + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n >> k >> s;
    for (int i = 0; i < n; ++i) {
        cin >> l[i] >> r[i];
        --l[i]; --r[i];
        if (l[i] >= 0) parent[l[i]] = i;
        if (r[i] >= 0) parent[r[i]] = i;
    }
    parent[0] = -1;
    buildStr(0);
    nxtInDfs = dfsString;
    char cur = ' ';
    for (int i = n - 1; i >= 0; --i) {
        nxtInDfs[i] = cur;
        if (i > 0 && dfsString[i - 1] != dfsString[i])
            cur = dfsString[i];
    }
    dfsSolve(0);
    dfsString.clear();
    buildStr(0, true);
    cout << dfsString << '\n';
}