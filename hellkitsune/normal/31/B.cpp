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

string s, t;
const string nosol = "No solution";

int main() {
    cin >> s;
    int flag = 0;
    for (char c : s) {
        if (flag == 0) {
            if (c == '@') {
                cout << nosol << endl;
                return 0;
            }
            t += c;
            flag = 1;
        } else if (flag == 1) {
            if (c == '@') {
                flag = 2;
            }
            t += c;
        } else if (flag == 2) {
            if (c == '@') {
                cout << nosol << endl;
                return 0;
            }
            t += c;
            flag = 3;
        } else if (flag == 3) {
            if (c == '@') {
                cout << nosol << endl;
                return 0;
            }
            t += c;
            flag = 4;
        } else {
            if (c == '@') {
                char tmp = t.back();
                t.pop_back();
                t += ',';
                t += tmp;
                flag = 2;
            }
            t += c;
        }
    }
    if (flag == 1 || flag == 2) {
        cout << nosol << endl;
        return 0;
    }
    cout << t << endl;
    return 0;
}