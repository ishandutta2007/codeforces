#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
char s[100005];
int sum[100005];
int i, n, l, r, m;
int main(){
    scanf("%s", s + 1);
    n = strlen(s + 1);
    for (i = 1; i <= n; i++) sum[i] = sum[i - 1] + (s[i] == s[i - 1]);
    scanf("%d", &m);
    for (i = 1; i <= m; i++){
        scanf("%d%d", &l, &r);
        printf("%d\n", sum[r] - sum[l]);
    }
}