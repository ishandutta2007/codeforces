#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
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

int n,m,k,x[105][105],ans[105],used[105],usedc[105];

void fail(int idx, int mov) {
    if (!ans[idx]) ans[idx] = mov;
    used[idx] = 1;
}

int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            scanf("%d",&x[i][j]);

    for (int i = 0; i < m; ++i) {
        int u[105] = {};
        for (int j = 0; j < n; ++j) {
            if (!used[j])
                ++u[x[j][i]];
            else x[j][i] = 0;
        }
        for (int j = 0; j < n; ++j) {
            if (!x[j][i]) continue;
            if (u[x[j][i]] > 1) {
                usedc[x[j][i]] = 1;
                for (int z = 0; z < n; ++z) {
                    if (x[z][i] == x[j][i]) fail(z,i+1);
                }
            } else {
                if (usedc[x[j][i]])
                    fail(j,i+1);
            }
        }
    }

    for (int i = 0; i < n; ++i)
        printf("%d\n",ans[i]);

    return 0;
}