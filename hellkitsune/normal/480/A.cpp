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

int n;
PII a[5000];

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    REP(i, n) cin >> a[i].first >> a[i].second;
    sort(a, a + n);
    for (int i = 1; i < n; ++i) if (a[i].second < a[i - 1].second)
        a[i].second = a[i].first;
    cout << a[n - 1].second << '\n';
    return 0;
}