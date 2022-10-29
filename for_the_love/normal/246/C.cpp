#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int mo = 1e8+7;
int ans[2000][60];
int cnt[2000];
int q[2000];
bool v[mo];
int main(){
    int n, k, tmp, i, j, x, limit, top;
    scanf("%d%d", &n, &k);
    q[0] = 0; top = 0;
    for (i = 1; i <= n; i++){
        scanf("%d", &tmp);
        if (!k) continue;
        limit = top;
        for (j = 0; j <= limit; j++){
            if (!v[(q[j] + tmp) % mo]){
                v[(q[j] + tmp) % mo] = 1;
                cnt[++top] = cnt[j] + 1;
                q[top] = q[j] + tmp;
                printf("%d ", cnt[top]);
                for (x = 1; x < cnt[top]; x++){
                    ans[top][x] = ans[j][x];
                    printf("%d ", ans[top][x]);
                }
                ans[top][cnt[top]] = tmp;
                printf("%d\n", tmp);
                k--;
                if (!k) break;
            }
        }
    }
    return 0;
}