#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;
typedef long long ll;
typedef long double ld;

int n,m,u[1005][1005],k,x,y;

int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for (int i = 1; i <= k; ++i) {
        scanf("%d%d",&x,&y);
        u[x][y] = 1;
        if ((u[x][y] && u[x][y+1] && u[x+1][y] && u[x+1][y+1]) ||
            (u[x][y] && u[x][y-1] && u[x+1][y] && u[x+1][y-1]) ||
            (u[x][y] && u[x][y+1] && u[x-1][y] && u[x-1][y+1]) ||
            (u[x][y] && u[x][y-1] && u[x-1][y] && u[x-1][y-1]))
        {
            printf("%d",i);
            return 0;
        }
    }
    printf("0");
    return 0;
}