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

int main() {
    cin >> s >> t;
    for (int i = (int)s.length() - 1; i >= 0; --i) if (s[i] != 'z') {
        ++s[i];
        for (int j = i + 1; j < (int)s.length(); ++j)
            s[j] = 'a';
        break;
    }
    if (s != t) cout << s << endl;
    else cout << "No such string" << endl;
    return 0;
}