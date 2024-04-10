#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <vector>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 111111;

int cnt[N][3], a[3];
char s[N];


int main(){
    int n, l, r;
    //freopen("in.txt", "r", stdin);
    scanf("%s", s + 1);
    n = strlen(s + 1);
    for (int i = 1; i <= n; i++){
        for (int j = 0; j < 3; j++) cnt[i][j] = cnt[i - 1][j];
        cnt[i][s[i] - 'x']++;
    }
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        scanf("%d%d", &l, &r);
        for (int j = 0; j < 3; j++) a[j] = cnt[r][j] - cnt[l - 1][j];
        sort(a, a + 3);
        if (r - l <= 1 || a[2] - a[0] <= 1) puts("YES"); else puts("NO");
    }

}


//int main(){
//    scanf("%d%d%d")
//
//}