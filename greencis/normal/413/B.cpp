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
#include <bitset>
using namespace std;

int n,m,k,a[20005][15],x,y,ans[20005],chat[11];

int main()
{
    ios_base::sync_with_stdio(0);
    scanf("%d%d%d",&n,&m,&k);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            scanf("%d",&a[i][j]);
    while (k--) {
        scanf("%d%d",&x,&y);
        --x; --y;
        --ans[x];
        ++chat[y];
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[j][i])
                ans[j] += chat[i];
        }
    }
    for (int i = 0; i < n; ++i) printf("%d ",ans[i]);

    return 0;
}