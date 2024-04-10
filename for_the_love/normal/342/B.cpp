#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int n, m, st, ed, p, l, r, now, t;
char ans[111111];
int main(){
    scanf("%d%d%d%d", &n, &m, &st, &ed);
    if (st < ed) p = 1; else p = -1;
    now = 1;
    for (int i = 1; i <= m; i++){
        scanf("%d%d%d", &t, &l, &r);
        while (now < t){
            st += p;
            if (p == 1) putchar('R'); else putchar('L');
            if (st == ed) return 0;
            now++;
        }
        if ((st > r || st < l) && (st + p > r || st + p < l)){
            st += p;
            if (p == 1) putchar('R'); else putchar('L');
        }else putchar('X');
        if (st == ed) return 0;
        now++;
    }
    for (int i = min(st, ed) + 1; i <= max(st, ed); i++) if (p == 1) putchar('R'); else putchar('L');
}