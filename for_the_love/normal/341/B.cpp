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
const int N = 111111;
int g[N], a[N], n;
int Find(int x){
    int l = 0, r = n, ret = 0;
    while (l <= r){
        int mid = l + r >> 1;
        if (g[mid] < x){
            ret = mid;
            l = mid + 1;
        }else r = mid - 1;
    }
    return ret;
}

int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    memset(g, 0x7f, sizeof(g));
    g[0] = 0;
    for (int i = 1; i <= n; i++){
        int j = Find(a[i]);
        g[j + 1] = min(g[j + 1], a[i]);
    }
    for (int i = n; i >= 1; i--)
    if (g[i] < 1e9){printf("%d\n", i); break;}
}