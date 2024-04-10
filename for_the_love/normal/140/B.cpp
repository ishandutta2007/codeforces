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

int c[305][305], f[305], ans[305], n, t, t1, t2;;
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n + 1; i++)
    for (int j = 1; j <= n; j++){
        scanf("%d", &t);
        c[i][t] = n - j + 1;
    }
    for (int i = 1; i <= n; i++){
        if (c[n + 1][i] > c[n + 1][t1]){
            t2 = t1;
            t1 = i;
        }else if (c[n + 1][i] > c[n + 1][t2]) t2 = i;
        for (int j = 1; j <= n; j++)
        if (t1 == j){
            if (c[j][t2] > f[j]){
                f[j] = c[j][t2];
                ans[j] = i;
            }
        }else{
            if (c[j][t1] > f[j]){
                f[j] = c[j][t1];
                ans[j] = i;
            }
        }
    }
    for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
}