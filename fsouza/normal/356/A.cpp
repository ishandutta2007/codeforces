#include <iostream>
#include <cstdio>
#include <algorithm>
#include <numeric>
#include <climits>
#include <sstream>
#include <cstring>
#include <cassert>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <map>
#include <set>

#define INF (INT_MAX/3)
#define MAXN 300000

typedef long long lint;

using namespace std;

int conquer[MAXN];

int main(int argc, char ** argv)
{
    int n, m;
    set<int> knights;

    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        knights.insert(i);
        conquer[i] = -1;
    }

    vector <int> todelete;

    todelete.reserve(n);

    for (int i = 0; i < m; i++) {
        int l, r, x;
        scanf("%d %d %d", &l, &r, &x);
        l--, r--, x--;

        set<int>::iterator it = knights.lower_bound(l);

        todelete.clear();

        for (; it != knights.end() && *it <= r; it++) {
            if (*it != x) {
                conquer[*it] = x;
                todelete.push_back(*it);
            }
        }

        for (int j = 0; j < (int)todelete.size(); j++)
            knights.erase(todelete[j]);
    }

    for (int i = 0; i < n; i++) {
        printf("%d", conquer[i]+1);
        if (i+1 < n) printf(" ");
    }
    printf("\n");

    return 0;
}