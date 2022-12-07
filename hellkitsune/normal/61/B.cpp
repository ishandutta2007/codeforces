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

string a[3], b[6];
char s[666];
int n;

string whaaaat(string s) {
    string ans;
    for (char c : s) if (c >= 'a' && c <= 'z') {
        ans += c;
    } else if (c >= 'A' && c <= 'Z') {
        ans += char(c - 'A' + 'a');
    }
    return ans;
}

int main() {
    REP(i, 3) {
        scanf("%s", s);
        string t(s);
        a[i] = whaaaat(t);
    }
    b[0] = a[0] + a[1] + a[2];
    b[1] = a[0] + a[2] + a[1];
    b[2] = a[1] + a[0] + a[2];
    b[3] = a[1] + a[2] + a[0];
    b[4] = a[2] + a[0] + a[1];
    b[5] = a[2] + a[1] + a[0];
    scanf("%d", &n);
    REP(i, n) {
        scanf("%s", s);
        string t(s);
        t = whaaaat(t);
        bool ok = false;
        REP(j, 6) if (b[j] == t) {
            printf("ACC\n");
            ok = true;
            break;
        }
        if (!ok) printf("WA\n");
    }
    return 0;
}