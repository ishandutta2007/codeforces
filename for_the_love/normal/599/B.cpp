#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;

int f[N], pos[N], cnt[N], ans[N];
int n, m, x;
int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++){
        scanf("%d", &f[i]);
        cnt[f[i]]++;
        pos[f[i]] = i;
    }
    int flag = 0;
    for (int i = 1; i <= m; i++){
        scanf("%d", &x);
        if (cnt[x] == 0){
            puts("Impossible");
            return 0;
        }else if (cnt[x] > 1){
            flag = 1;
        }else ans[i] = pos[x];
    }
    if (flag) puts("Ambiguity");
    else{
        puts("Possible");
        for (int i = 1; i <= m; i++)
            printf("%d ", ans[i]);
    }
}