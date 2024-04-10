#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
struct node{
    int a[101];
} s;
int n, k, i, q[101], p[101];
node work1(int k){
    node t1,t2;
    int i, j;
    t1 = s;
    for (i = 1; i <= k; i++){
        for (j = 1; j <= n; j++) t2.a[j] = t1.a[q[j]];
        t1 = t2;
    }
    return t1;
}
node work2(int k){
    node t1,t2;
    int i, j;
    t1 = s;
    for (i = 1; i <= k; i++){
        for (j = 1; j <= n; j++) t2.a[q[j]] = t1.a[j];
        t1 = t2;
    }
    return t1;
}
int check(node x){
    int i;
    for (i = 1; i <= n; i++) if (x.a[i] != p[i]) return 0;
    return 1;
}
int main(){
    scanf("%d%d", &n, &k);
    for (i = 1; i <= n; i++) s.a[i] = i;
    for (i = 1; i <= n; i++) scanf("%d", &q[i]);
    for (i = 1; i <= n; i++) scanf("%d", &p[i]);
    if (check(work1(0))){
        printf("NO");
        return 0;
    }
    if (check(work1(1)) && check(work2(1))){
        if (k > 1) printf("NO"); else printf("YES");
        return 0;
    }

    for (i = 1; i <= k; i++){
        if ((k - i) % 2 != 0) continue;
        if (check(work1(i)) || check(work2(i))){
            printf("YES");
            return 0;
        }
    }
    printf("NO");
}