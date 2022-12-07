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

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); e++)
typedef long long LL;
typedef pair<int, int> PII;

char s[1000005];
int cur = 0;
int bal = 0;
int best = 0;
int cnt = 1;
set<int> pos;

int main() {
    scanf("%s", s);
    int n = strlen(s);
    REP(i, n) {
        if (s[i] == '(') ++bal;
        else --bal;
        if (bal < 0) {
            cur = 0;
            bal = 0;
        } else {
            ++cur;
            if (bal == 0) {
                if (cur > best) {
                    best = cur;
                    cnt = 1;
                    pos.clear();
                    pos.insert(i - cur + 1);
                } else if (cur == best) {
                    ++cnt;
                    pos.insert(i - cur + 1);
                }
            }
        }
    }
    cur = bal = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == '(') --bal;
        else ++bal;
        if (bal < 0) {
            cur = 0;
            bal = 0;
        } else {
            ++cur;
            if (bal == 0) {
                if (cur > best) {
                    best = cur;
                    cnt = 1;
                    pos.clear();
                } else if (cur == best) {
                    if (!pos.count(i))
                        ++cnt;
                }
            }
        }
    }
    cout << best << ' ' << cnt << endl;
    return 0;
}