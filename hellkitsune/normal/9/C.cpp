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

int get(string x) {
    int n = x.length();
    if (x[0] > '1') return 1 << n;
    if (x[0] == '1') return (1 << (n - 1)) + ((n == 1) ? 1 : get(x.substr(1)));
    return (n == 1) ? 1 : get(x.substr(1));
}

string x;

int main() {
    cin >> x;
    cout << get(x) - 1 << endl;
    return 0;
}