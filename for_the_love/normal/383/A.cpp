#pragma  comment(linker, "/STACK:36777216")
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <iomanip>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 2e6 + 7;

int a[N], s[N][2], n;

int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        s[i][a[i]] = s[i - 1][a[i]] + 1;
        s[i][a[i] ^ 1] = s[i - 1][a[i] ^ 1];
    }
    long long ans = 0;

    for (int i = 1; i <= n; i++)
    if (a[i] == 1) ans += s[n][0] - s[i][0];
    cout << ans << endl;
}