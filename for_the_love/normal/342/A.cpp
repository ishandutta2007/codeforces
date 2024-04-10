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

int n, res, x, cnt[10], ans[55555][3];

int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        scanf("%d", &x);
        cnt[x]++;
    }

    for (int i = 1; i <= cnt[4]; i++){
        cnt[2]--;
        cnt[1]--;
        if (cnt[1] < 0 || cnt[2] < 0){
            puts("-1");
            return 0;
        }
        ans[++res][0] = 1;
        ans[res][1] = 2;
        ans[res][2] = 4;
    }
    for (int i = 1; i <= cnt[6]; i++){
        if (cnt[2]){
            cnt[2]--;
            cnt[1]--;
            ans[++res][0] = 1;
            ans[res][1] = 2;
            ans[res][2] = 6;
            if (cnt[1] < 0 || cnt[2] < 0){
                puts("-1");
                return 0;
            }
        }else{
            cnt[3]--;
            cnt[1]--;
            ans[++res][0] = 1;
            ans[res][1] = 3;
            ans[res][2] = 6;
            if (cnt[1] < 0 || cnt[3] < 0){
                puts("-1");
                return 0;
            }
        }
    }
    cnt[6] = cnt[4] = 0;
    for (int i = 1; i <= 7; i++) if (cnt[i]){puts("-1"); return 0;};
    for (int i = 1; i <= res; i++) printf("%d %d %d\n", ans[i][0], ans[i][1], ans[i][2]);
}