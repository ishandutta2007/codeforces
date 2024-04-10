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

#define INF (INT_MAX/2)
#define MAXN 100000
#define MAXE MAXN

typedef long long lint;

using namespace std;

int ne = 0;
pair <int, pair <int, int> > edges[MAXE];

int np = 0;
pair <int, int> pairs[2*MAXN];

void solve(int n)
{
        int l = 1, m = n, r = n-1;

        for (int a = 2; a < r; a += 2) {
                edges[ne++] = make_pair(1, make_pair(a, l));
                if (a-1 > 1)
                        pairs[np++] = make_pair(a, a-1);
                pairs[np++] = make_pair(a, a+1);
        }

        edges[ne++] = make_pair(1, make_pair(l, m));
        edges[ne++] = make_pair(2*(n-1)/2 - 3, make_pair(m, r));

        for (int b = 3; b < m; b += 2)
                edges[ne++] = make_pair(1, make_pair(b, r));
}

int main(int argc, char ** argv)
{
        int n;

        scanf("%d", &n);

        if (n == 5) {
                printf("1 4 1\n2 3 2\n2 5 1\n3 4 2\n1 2\n4 5\n");
                return 0;
        } else if (n == 6) {
                printf("1 2 4\n1 3 4\n1 5 1\n2 6 2\n4 6 1\n3 4\n4 5\n5 6\n");
                return 0;
        } else if (n == 8) {
                printf("1 3 3\n1 7 1\n2 3 3\n2 4 2\n3 6 2\n4 5 3\n7 8 2\n5 7\n5 8\n6 7\n6 8\n");
                return 0;
        }

        if (n%2 == 1) {
                solve(n);
        } else {
                solve(n-1);
                edges[ne++] = make_pair(1, make_pair(n, n-1));
        }

        int need = n/2;

        if (np < need) {
                printf("FAIL.\n");
                return 0;
        }

        assert(ne == n-1);
        for (int i = 0; i < ne; i++) {
                int c = edges[i].first;
                int a = edges[i].second.first;
                int b = edges[i].second.second;
                if (a > b) swap(a, b);
                printf("%d %d %d\n", a, b, c);
        }

        for (int j = 0; j < min(need, np); j++) {
                if (pairs[j].first > pairs[j].second)
                        swap(pairs[j].first, pairs[j].second);
                printf("%d %d\n", pairs[j].first, pairs[j].second);
        }

        return 0;
}