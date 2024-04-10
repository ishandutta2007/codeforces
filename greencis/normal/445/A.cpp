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

int n,m;
char p[999][999];

int main()
{
    scanf("%d%d",&n,&m);
    for (int i = 0; i < n; ++i)
        scanf("%s",p[i]);

    for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
        if (p[i][j] == '.') {
            if ((i + j)%2) p[i][j] = 'W';
            else p[i][j] = 'B';
        }
    }
    for (int i = 0; i< n;++i)
        printf("%s\n",p[i]);

    return 0;
}