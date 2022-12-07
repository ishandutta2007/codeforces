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
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); ++e)
typedef long long LL;
typedef pair<int, int> PII;

int f[33000];
string s, t;
int n;
const int MOD = 32768;

int parseArithm(int from, int to) {
    int sgn = '+', lst = '+';
    int sum = 0, prod = -1;
    for (int i = from; i <= to; ) {
        if (s[i] >= '0' && s[i] <= '9') {
            int num = 0;
            while (s[i] >= '0' && s[i] <= '9') {
                num = 10 * num + s[i] - '0';
                ++i;
            }
            if (prod == -1) prod = num;
            else if (lst == '*') {
                prod = (prod * num) % MOD;
            } else {
                prod = (prod / num);
            }
            continue;
        }
        if (s[i] == 'f') {
            int st = i, ed;
            int bal = 0;
            for (ed = i + 1; s[ed] != ')' || --bal > 0; ++ed) if (s[ed] == '(') {
                if (++bal == 1) st = ed;
            }
            i = ed + 1;
            int num = parseArithm(st + 1, ed - 1);
            num = f[num];
            if (prod == -1) prod = num;
            else if (lst == '*') {
                prod = (prod * num) % MOD;
            } else {
                prod = (prod / num);
            }
            continue;
        }
        if (s[i] == 'n') {
            ++i;
            int num = n;
            if (prod == -1) prod = num;
            else if (lst == '*') {
                prod = (prod * num) % MOD;
            } else {
                prod = (prod / num);
            }
            continue;
        }
        if (s[i] == '+' || s[i] == '-') {
            if (prod != -1) {
                if (sgn == '+') {
                    sum += prod;
                    if (sum >= MOD) sum -= MOD;
                } else {
                    sum -= prod;
                    if (sum < 0) sum += MOD;
                }
                prod = -1;
            }
            sgn = s[i];
        }
        if (s[i] == '*' || s[i] == '/' || s[i] == '+' || s[i] == '-') {
            lst = s[i];
        }
        ++i;
    }
    if (prod != -1) {
        if (sgn == '+') {
            sum += prod;
            if (sum >= MOD) sum -= MOD;
        } else {
            sum -= prod;
            if (sum < 0) sum += MOD;
        }
    }
    return sum;
}

int parseReturn(int from) {
    while (s[from] != 'n') ++from;
    ++from;
    int to = from;
    while (s[to] != ';') ++to;
    --to;
    return parseArithm(from, to);
}

bool parseLogical(int from, int to) {
    for (int i = from; i <= to; ++i) if (s[i] == '<' || s[i] == '>' || s[i] == '=') {
        int j = i;
        if (s[i] == '=') ++j;
        int leftVal = parseArithm(from, i - 1);
        int rightVal = parseArithm(j + 1, to);
        return (s[i] == '<' && leftVal < rightVal) ||
            (s[i] == '>' && leftVal > rightVal) ||
            (s[i] == '=' && leftVal == rightVal);
    }
    assert(false);
    return false;
}

int calc(int from, int to) {
    for (int i = from; i <= to; ) {
        if (s[i] != 'i' && s[i] != 'r') {
            ++i;
            continue;
        }
        if (s[i] == 'i') {
            int st = i, ed;
            int bal = 0;
            for (ed = i + 1; s[ed] != ')' || --bal > 0; ++ed) if (s[ed] == '(') {
                if (++bal == 1) st = ed;
            }
            if (parseLogical(st + 1, ed - 1)) {
                return parseReturn(ed + 1);
            }
            while (s[i] != ';') ++i;
            ++i;
            continue;
        }
        return parseReturn(i);
    }
    return 0;
}

int calc() {
    int st = 0, ed = 0;
    REP(i, s.length()) if (s[i] == '{') {
        st = i + 1;
    } else if (s[i] == '}') {
        ed = i - 1;
    }
    return calc(st, ed);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int targ;
    cin >> targ;
    while (cin >> t) {
        s += " " + t;
    }
    for (n = 0; n < 32768; ++n) {
        f[n] = calc();
    }
    for (int i = 32767; i >= 0; --i) if (f[i] == targ) {
        cout << i << endl;
        return 0;
    }
    cout << -1 << endl;
    return 0;
}