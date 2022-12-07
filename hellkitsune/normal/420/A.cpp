#include <cstdio>
#include <cmath>
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

bool t[255] = {};
string s;

int main() {
    t['A'] = t['H'] = t['I'] = t['M'] = t['O'] = t['T'] = t['U'] = t['V'] = t['W'] = t['X'] = t['Y'] = true;
    cin >> s;
    int n = s.length();
    REP(i, (n + 1) / 2)
        if (!t[s[i]] || s[i] != s[n - 1 - i]) {
            cout << "NO" << endl;
            return 0;
        }
    cout << "YES" << endl;
    return 0;
}