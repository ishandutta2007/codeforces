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

int a, b;
char s[1005];
LL x = 0;

int ctoi(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    return c - 'A' + 10;
}

char itoc(int i) {
    if (i < 10) return '0' + i;
    return 'A' + (i - 10);
}

char q[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};

int main() {
    scanf("%d%s", &a, s);
    if (s[0] == 'R') b = -1;
    else {
        string t(s);
        istringstream iss(t);
        iss >> b;
    }
    scanf("%s", s);
    int len = strlen(s);
    REP(i, len) {
        x = a * x + ctoi(s[i]);
    }
    string ans;
    if (b != -1) {
        while (x) {
            ans += itoc(x % b);
            x /= b;
        }
        reverse(ans.begin(), ans.end());
        if (ans.empty()) ans += '0';
    } else {
        int off = 0;
        while (x) {
            string s;
            int cur = x % 10;
            x /= 10;
            if (cur < 4) {
                REP(i, cur) s += q[off];
            } else if (cur == 4) {
                s += q[off];
                s += q[off + 1];
            } else if (cur == 5) {
                s += q[off + 1];
            } else if (cur < 9) {
                s += q[off + 1];
                REP(i, cur - 5) s += q[off];
            } else {
                s += q[off];
                s += q[off + 2];
            }
            off += 2;
            ans = s + ans;
        }
    }
    cout << ans << endl;
    return 0;
}