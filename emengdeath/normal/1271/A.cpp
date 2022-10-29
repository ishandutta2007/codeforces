#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std;
int a, b, c, d, e, f;
int main(){
    scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);
    long long ans = 0;
    for (int i = 0; i <= min(a, d);i ++) {
        int sum = min(b, min(c, d - i));
        ans = max(ans, 1ll * i * e + 1ll * f * sum);
    }
    cout<<ans;
    return 0;
}