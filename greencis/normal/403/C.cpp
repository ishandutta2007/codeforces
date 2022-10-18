#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <utility>
#include <deque>
using namespace std;

int n,a[2005][2005],t,res,u[2005];

void dfs(int v) {
    if (!u[v]) {
        u[v] = 1;
        ++res;
        for (int i = 0; i < n; ++i) {
            if (a[v][i] && !u[i])
                dfs(i);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d",&t);
            a[i][j] = t > 0;
        }
    }

    dfs(0);
    for (int i = 0; i < n; ++i) {
        u[i] = 0;
        for (int j = i+1; j < n; ++j) {
            swap(a[i][j],a[j][i]);
        }
    }
    dfs(0);

    if (res < 2*n) printf("NO");
    else printf("YES");

    return 0;
}