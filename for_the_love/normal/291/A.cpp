#include <map>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

map <int, int> S;
int n, x, ans, i;
int main(){
    scanf("%d", &n);
    for (i = 1; i <= n; i++){
        scanf("%d", &x);
        if (x == 0) continue;
        S[x]++;
        if (S[x] == 2) ans++;
        if (S[x] == 3){
            printf("-1\n");
            return 0;
        }
    }
    printf("%d\n", ans);
}