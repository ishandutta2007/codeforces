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

string s, t;
int cnt[53];

int charToInt(char c) {
    if (c >= 'a' && c <= 'z') return c - 'a';
    if (c >= 'A' && c <= 'Z') return c - 'A' + 26;
    return 52;
}

int main() {
    getline(cin, s);
    getline(cin, t);
    for (char c : s) ++cnt[charToInt(c)];
    for (char c : t) --cnt[charToInt(c)];
    REP(i, 52) if (cnt[i] < 0) {
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    return 0;
}