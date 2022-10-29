#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
struct node{
    int a; double b, c, d;
} t[50005];
int i, n, tmp;
double ans, sum, sumb, sumc;
int cmp(node a, node b){return a.d > b.d;}
int main(){
    scanf("%d", &n);
    for (i = 1; i <= n; i++){
        scanf("%d%d", &t[i].a, &tmp);
        t[i].b = tmp / 100.0;
        t[i].c = t[i].a * t[i].b;
        t[i].d = t[i].c / (1 - t[i].b);
    }
    sort(t + 1, t + n + 1, cmp);
    sum = 0;
    for (i = 1; i <= n; i++){
        ans += sum * (1 - t[i].b) + t[i].a;
        sum += t[i].c;
    }
    printf("%lf\n", ans);
}