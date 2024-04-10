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
struct Pnode{
    int x, y;
} p[200010];


map <int, int> S;
int a[100005], b[100005], s[200005], n, m, k, cnt, i, j;
int cmp(Pnode a, Pnode b){return a.x < b.x;}
int main(){
    scanf("%d%d%d", &n, &m, &k);
    for (i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        S[a[i]]++;
    }
    for (i = 1; i <= m; i++){
        scanf("%d", &b[i]);
        S[b[i]]--;
    }
    for (i = 1; i <= n; i++)
    if (S[a[i]] != 0){
        p[++cnt].x = a[i];
        p[cnt].y = S[a[i]];
        S[a[i]] = 0;
    }
    for (i = 1; i <= m; i++)
    if (S[b[i]] != 0){
        p[++cnt].x = b[i];
        p[cnt].y = S[b[i]];
        S[b[i]] = 0;
    }
    sort(p + 1, p + cnt + 1, cmp);
    for (i = 1; i <= cnt; i++) s[i] = s[i - 1] + p[i].y;
    for (i = 1; i <= cnt; i++)
    if (p[i].y > 0 && s[cnt] - s[i - 1] > 0){
        printf("YES\n");
        return 0;
    }
    printf("NO\n");
}