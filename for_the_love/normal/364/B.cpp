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
#define DB double

#define REP(i, n) for (int i=0;i<n;++i)
#define FOR(i, a, b) for (int i=a;i<b;++i)
#define checkMin(a, b) a = min(a, b)
#define checkMax(a, b) a = max(a, b)


using namespace std;
const int M = 555555;

int b[M];

int main(){
    int n, d;
    scanf("%d%d", &n, &d);
    b[0] = 1;
    for (int i = 1; i <= n; i++){
        int x;
        scanf("%d", &x);
        for (int j = M - 1; j >= x; j--)
        if (b[j - x]) b[j] = 1;
    }
    int x = 0, ans = 0;
    while (1){
        int flag = 0;
        for (int i = x + d; i > x; i--)
        if (b[i]){
            flag = 1;
            x = i;
            ans++;
            break;
        }
        if (!flag) break;
    }
    printf("%d %d\n", x, ans);
}