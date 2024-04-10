#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int n, i, cnt, ans, a;
int res[1000];
int main(){
    scanf("%d", &n);
    ans = 1;
    for (i = 1; i <= n; i++){
        scanf("%d", &a);
        if (a < 0) cnt++;
        if (cnt > 2){
            ans++;
            cnt = 1;
        }
        res[ans]++;
    }
    printf("%d\n", ans);
    for (i = 1; i <= ans; i++) printf("%d ", res[i]);

}