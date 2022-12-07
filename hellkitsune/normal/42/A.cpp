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

int n, v;
int a[20], b[20];

int main() {
    scanf("%d%d", &n, &v);
    REP(i, n) scanf("%d", a + i);
    REP(i, n) scanf("%d", b + i);
    int sum = 0;
    REP(i, n) sum += a[i];
    double x = v / (double)sum;
    REP(i, n) x = min(x, b[i] / (double)a[i]);
    printf("%.12f\n", x * sum);
    return 0;
}