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
int n;

int main() {
    cin >> s >> t;
    n = (int)s.length();
    REP(i, n) if (s[i] == t[i]) s[i] = '0';
    else s[i] = '1';
    cout << s << endl;
    return 0;
}