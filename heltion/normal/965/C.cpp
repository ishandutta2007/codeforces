#include<cstdio>
#include<algorithm>
int main(){
    long long n, k, M, D, ans;
    scanf("%lld %lld %lld %lld", &n, &k, &M, &D);
    ans = (n / M / k + !!(n / M % k)) * M;
    for(int d = 1; d <= D; d += 1){
        long long x = n / ((d - 1) * k + 1);
        if(x == 0) break;
        if(x <= M && x > n % ((d - 1) * k + 1)) ans = std::max(ans, x * d);
    }
    printf("%lld", ans);
}