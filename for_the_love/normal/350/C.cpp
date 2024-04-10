#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
struct Pnode{
    int x, y;
} p[111111];

bool cmp(Pnode a, Pnode b){return abs(a.x) + abs(a.y) < abs(b.x) + abs(b.y);}
int n, t[1111111], ans[1111111];
char ch[1111111];

int main(){
    int cnt = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d%d", &p[i].x, &p[i].y);
    sort(p + 1, p + n + 1, cmp);
    for (int i = 1; i <= n; i++){
        char c1, c2;
        if (p[i].x < 0) c1 = 'L'; else c1 = 'R';
        if (p[i].y < 0) c2 = 'D'; else c2 = 'U';
        if (p[i].x){
            t[++cnt] = 1;
            ans[cnt] = abs(p[i].x);
            ch[cnt] = c1;
        }
        if (p[i].y){
            t[++cnt] = 1;
            ans[cnt] = abs(p[i].y);
            ch[cnt] = c2;
        }
        t[++cnt] = 2;
        if (p[i].x < 0) c1 = 'R'; else c1 = 'L';
        if (p[i].y < 0) c2 = 'U'; else c2 = 'D';
        if (p[i].x){
            t[++cnt] = 1;
            ans[cnt] = abs(p[i].x);
            ch[cnt] = c1;
        }
        if (p[i].y){
            t[++cnt] = 1;
            ans[cnt] = abs(p[i].y);
            ch[cnt] = c2;
        }
        t[++cnt] = 3;
    }
    printf("%d\n", cnt);
    for (int i = 1; i <= cnt; i++){
        if (t[i] == 1) printf("%d %d %c\n", 1, ans[i], ch[i]);
        else printf("%d\n", t[i]);

    }
}