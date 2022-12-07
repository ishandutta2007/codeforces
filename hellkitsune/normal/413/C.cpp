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

int n, m;
pair<int, bool> a[100];
LL score = 0;

int main() {
    scanf("%d%d", &n, &m);
    REP(i, n) {
        scanf("%d", &a[i].first);
        a[i].second = false;
    }
    REP(i, m) {
        int x;
        scanf("%d", &x);
        a[x - 1].second = true;
    }
    sort(a, a + n, std::greater<pair<int, bool> >());
    REP(i, n) if (!a[i].second)
        score += a[i].first;
    REP(i, n) if (a[i].second) {
        if (a[i].first < score)
            score <<= 1;
        else
            score += a[i].first;
    }
    cout << score << endl;
    return 0;
}