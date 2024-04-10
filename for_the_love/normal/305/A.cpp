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

int a[10], t, n, i, tmp, ans, f1, f2, f3, f4;
int main(){
    scanf("%d", &n);
    for (i = 1; i <= n; i++){
        scanf("%d", &t);
        if (!t){
            a[++ans] = 0;
            continue;
        }
        if (t == 100){
            a[++ans] = 100;
            continue;
        }
        if (t % 10 == 0){
            if (f1) continue;
            f1 = 1;
            a[++ans] = t;
            continue;
        }
        if (t < 10){
            if (f2) continue;
            f2 = 1;
            a[++ans] = t;
            continue;
        }
        if (t > 10 && t < 100){
            tmp = t;
        }
    }
    if (ans == 4){
        printf("%d\n", ans);
        for (i = 1; i <= 4; i++) printf("%d ", a[i]);
    }else{
        if (ans == 3){
            printf("%d\n", ans);
            for (i = 1; i <= 3; i++) printf("%d ", a[i]);
        }else{
            if (!f1 && !f2 && tmp){
                printf("%d\n", ans + 1);
                for (i = 1; i <= ans; i++) printf("%d ", a[i]);
                printf("%d\n", tmp);
            }else{
                printf("%d\n", ans);
                for (i = 1; i <= ans; i++) printf("%d ", a[i]);
            }
        }
    }


}