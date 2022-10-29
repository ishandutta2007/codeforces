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

int n, m, i, x, y, p, a[1005];
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    scanf("%d", &m);
    while (m--){
        scanf("%d%d%d", &p, &x, &y);
        if (p == 2) swap(a[x], a[y]);
        else{
            int now = x;
            int ans = 0;
            while (now <= y){
                ans++;
                for (int i = 1; i <= n; i++)
                if (a[i] == now){
                    now++;
                }
            }
            printf("%d\n", ans);
        }
    }

}