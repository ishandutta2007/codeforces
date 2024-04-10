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

string s;
int n, m;

int main() {
    cin >> s;
    n = (int)s.length();
    m = 0;
    REP(i, n) if (s[i] >= 'a' && s[i] <= 'z') ++m;
    if (m * 2 >= n) {
        REP(i, n) if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] += 'a' - 'A';
        }
    } else {
        REP(i, n) if (s[i] >= 'a' && s[i] <= 'z') {
            s[i] += 'A' - 'a';
        }
    }
    cout << s << endl;
    return 0;
}