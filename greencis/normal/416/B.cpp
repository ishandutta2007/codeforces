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

int m,n,t[50005][9];
long long ans[50005][9];

int main()
{
    ios_base::sync_with_stdio(0);
    scanf("%d%d",&m,&n);
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            scanf("%d",&t[i][j]);
        }
    }

    for (int i = 1; i <= n; ++i) { /// ans[j][i]
        long long tm = 0ll;
        for (int j = 1; j <= m; ++j) {
            //cerr <<"AAA"<< tm << endl;
            tm = (long long)max((long long)ans[j][i-1], tm) + (long long)t[j][i];
            ans[j][i] = tm;
        }
    }

    for (int i = 1; i <= m; ++i)
        cout << ans[i][n] << " ";

    return 0;
}