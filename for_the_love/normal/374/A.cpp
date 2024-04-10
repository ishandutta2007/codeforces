#include <map>
#include <set>
#include <cmath>
#include <ctime>
#include <stack>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1111111;

int n, m, i, j, a, b;

int main(){
    //freopen("in.txt", "r", stdin);
    scanf("%d%d%d%d%d%d", &n, &m, &i, &j, &a, &b);
    int ans = 1e9;
    if (i == 1 && j == 1){puts("0"); return 0;}
    if (i == 1 && j == m){puts("0"); return 0;}
    if (i == n && j == m){puts("0"); return 0;}
    if (i == n && j == 1){puts("0"); return 0;}
    if (max(i - 1, n - i) < a || max(j - 1, m - j) < b){
        puts("Poor Inna and pony!");
        return 0;
    }
    if ((i - 1) % a == 0 && (j - 1) % b == 0 && (abs((i - 1) / a - (j - 1) / b) % 2 == 0)) ans = min(ans, max((i - 1) / a, (j - 1) / b));
    if ((i - 1) % a == 0 && (m - j) % b == 0 && (abs((i - 1) / a - (m - j) / b) % 2 == 0)) ans = min(ans, max((i - 1) / a, (m - j) / b));
    if ((n - i) % a == 0 && (j - 1) % b == 0 && (abs((n - i) / a - (j - 1) / b) % 2 == 0)) ans = min(ans, max((n - i) / a, (j - 1) / b));
    if ((n - i) % a == 0 && (m - j) % b == 0 && (abs((n - i) / a - (m - j) / b) % 2 == 0)) ans = min(ans, max((n - i) / a, (m - j) / b));

    if (ans == 1e9) puts("Poor Inna and pony!"); else printf("%d\n", ans);
}