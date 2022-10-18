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

int n,a[1005][1005];
int m,z1,z2,res;
bool diag[1005];

int main()
{
    ios_base::sync_with_stdio(0);
    //freopen("input.txt","r",stdin);
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d",&a[i][j]);
        }
    }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (i == j)
                diag[i] = a[i][j], res += a[i][j];
    res &= 1;
    scanf("%d",&m);
    while (m--) {
        scanf("%d",&z1);
        if (z1 == 3) {
            printf("%d",res&1);
        } else {
            scanf("%d",&z2); --z2;
            diag[z2] = !diag[z2];
            res = !res;
        }
    }

    return 0;
}