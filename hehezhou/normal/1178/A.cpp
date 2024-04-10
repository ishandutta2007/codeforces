
 #include<bits/stdc++.h>
using namespace std;
int a[101];
int ans[101];
int main() {
    int n;
    scanf("%d", &n);
    int sum = 0, mx = 0;
    for(int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        sum += a[i];
    }
    mx = a[1];
    ans[1] = 1;
    int tmp = a[1];
    int tot = 1;
    for(int i = 1; i <= n; i++) {
        if(a[i] * 2 <= mx) {
            tmp += a[i];
            ans[++tot] = i;
        }
    }
    if(tmp * 2 > sum) {
        printf("%d\n", tot);
        for(int i = 1; i <= tot; i++) {
            printf("%d ",ans[i]);
        }
    }
    else puts("0");
    return 0;
}