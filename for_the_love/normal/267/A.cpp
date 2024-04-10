#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int n, a, b, ans, c;

int main(){
    scanf("%d", &n);
    while (n--){
        scanf("%d%d", &a, &b);
        ans = 0;
        while (a && b){
            ans += max(a, b) / min(a, b);
            c = max(a, b) - max(a, b) / min(a, b) * min(a ,b);
            a = min(a, b);
            b = c;
        }
        printf("%d\n", ans);
    }

}