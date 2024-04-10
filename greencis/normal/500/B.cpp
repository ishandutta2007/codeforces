#include <iostream>
#include <algorithm>
#include <cstring>
#include <fstream>
#include <cstdio>
#include <string>
#include <cmath>
#include <vector>
#include <stack>
#include <cstdlib>
#include <iomanip>
#include <map>
#include <utility>
using namespace std;
typedef long long ll;
typedef long double ld;

int n,p[999],ans[999],t[999],u[999];
int d[999][999];
char a[999][999];


int main()
{
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        scanf("%d",&p[i]);
        ans[i] = p[i];
    }
    for (int i = 0; i < n; ++i)
        scanf("%s",a[i]);

    for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) {
        if (a[i][j] == '1') d[i][j] = 1;
        else d[i][j] = 1e9;
    }

    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

    for (int i = 0; i < n; ++i) {
        int mn = 2e9, mni = -1;
        for (int j = i + 1; j < n; ++j) {
            if (u[ans[j]] || d[i][j] >= 1e8) continue;
            if (ans[j] < mn) mn = ans[j], mni = j;
        }
        if (mni != -1 && mn < ans[i]) {
            swap(ans[i], ans[mni]);
            u[ans[i]] = 1;
        }
    }

    for (int i = 0; i < n; ++i)
        printf("%d ",ans[i]);


    return 0;
}