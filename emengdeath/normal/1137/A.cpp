#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <cstring>
#include <deque>
#include <set>
#include <vector>
#include <unordered_map>
using namespace std;
const int N = 3e6;
int n, m;
struct node{
    int sum, v;
}r[1001][1001], c[1001][1001];
int a[1001][1001], b[1001];
int er(int*a, int l, int r,int v){
    int mid;
    while (l <= r) {
        if (a[mid = (l + r)/ 2] == v) return mid;
        if (a[mid] > v) r = mid - 1;
        else
            l = mid + 1;
    }
}
int main(){
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n ; i ++) {
        for (int j = 1; j <= m; j++)
            scanf("%d", &a[i][j]);
    }
    for (int i = 1;i <= n ; i++)
    {
        for (int j = 1; j <= m ;j  ++)
            b[j] = a[i][j];
        sort(b + 1, b + m + 1);
        b[0] =1;
        for (int j = 1;j <= m ; j ++)
            if (b[b[0]] != b[j] )b[++b[0]] = b[j];
        for (int j = 1; j <= m ; j ++)
            r[i][j].sum = b[0], r[i][j].v = er(b, 1, b[0], a[i][j]);
    }
    for (int j = 1; j <= m ;  j++){
        for (int i = 1; i <= n; i ++)
            b[i] = a[i][j];
        sort(b + 1, b + n + 1);
        b[0] = 1;
        for (int i = 1; i <= n ; i ++)
            if (b[b[0]] != b[i]) b[++b[0]] = b[i];
        for (int i = 1; i <= n ; i ++)
            c[i][j].sum = b[0], c[i][j].v = er(b, 1, b[0], a[i][j]);
    }
    for (int i = 1; i <= n ; i++) {
        for (int j = 1; j <= m; j ++)
            printf("%d ", 1 + max(c[i][j].v - 1, r[i][j].v - 1) + max(c[i][j].sum - c[i][j].v, r[i][j].sum - r[i][j].v));
        printf("\n");
    }
    return 0;
}