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

int n,t,a[312345],u[312345];

int main()
{
    scanf("%d%d",&n,&t);
    for (int i = 1; i <= n-1; ++i) {
        scanf("%d",&a[i]);
    }
    int cur = 1;
    while (cur != n || !u[cur]) {
        u[cur] = 1;
        cur = cur + a[cur];
    }
    if (u[t]) cout << "YES";
    else cout << "NO";

    return 0;
}