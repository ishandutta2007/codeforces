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
int len[1000], ord[1000];
string s[1000];

inline bool cmp(const int &lhs, const int &rhs) {
    return len[lhs] < len[rhs];
}

bool addOne(string &s) {
    int ind = (int)s.length() - 1;
    while (s[ind] == '1') {
        s[ind] = '0';
        if (--ind < 0) {
            return false;
        }
    }
    s[ind] = '1';
    return true;
}

int main() {
    scanf("%d", &n);
    REP(i, n) scanf("%d", len + i);
    REP(i, n) ord[i] = i;
    sort(ord, ord + n, cmp);
    s[ord[0]] = string(len[ord[0]], '0');
    for (int ii = 1; ii < n; ++ii) {
        int i = ord[ii];
        int j = ord[ii - 1];
        s[i] = s[j];
        if (!addOne(s[i])) {
            printf("NO\n");
            return 0;
        }
        while ((int)s[i].length() < len[i]) {
            s[i] += '0';
        }
    }
    printf("YES\n");
    REP(i, n) printf("%s\n", s[i].c_str());
    return 0;
}