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

struct Node {
    map<string, int> e;
};

string s;
int nodeCount = 1;
Node nodes[12345];

int getHash(map<string, int> &ma, string s) {
    auto it = ma.find(s);
    if (it == ma.end()) {
        ma[s] = nodeCount;
        return nodeCount++;
    }
    return it->second;
}

int foldCur, fileCur;

void dfs(int v) {
    for (auto it : nodes[v].e) {
        if (nodes[it.second].e.empty()) ++fileCur;
        else ++foldCur;
        dfs(it.second);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    while (cin >> s) {
        int st = 0, node = 0;
        bool frst = true;
        s += '\\';
        REP(i, (int)s.length()) if (s[i] == '\\') {
            if (frst) {
                frst = false;
                continue;
            }
            node = getHash(nodes[node].e, s.substr(st, i - st));
            st = i + 1;
        }
    }
    int foldMax = 0, fileMax = 0;
    for (auto it : nodes[0].e) {
        foldCur = fileCur = 0;
        dfs(it.second);
        foldMax = max(foldMax, foldCur);
        fileMax = max(fileMax, fileCur);
    }
    cout << foldMax << ' ' << fileMax << endl;
    return 0;
}