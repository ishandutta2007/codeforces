#include<bits/stdc++.h>
long long a[100];
int n;
bool test(int i, int k, long long s){
    if(i + k > n) return false;
    if(i == n and k == 0) return true;
    long long sum = 0;
    for(int j = i; j < n; j += 1){
        sum += a[j];
        if((sum & s) == s and test(j + 1, k - 1, s)) return true;
    }
    return false;
}
int main(){
    int k;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i += 1) scanf("%lld", a + i);
    long long ans = 0, s = 1LL << 60;
    while(s){
        if(test(0, k, ans + s))ans += s;
        s >>= 1;
    }
    printf("%lld", ans);
}