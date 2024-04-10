 #include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    int ans = 1e9;
    ans = min(ans, a + b + c);
    ans = min(ans, a + a + c + c);
    ans = min(ans, a + b + a + b);
    ans = min(ans, b + c + b + c);
    printf("%d\n", ans);
}