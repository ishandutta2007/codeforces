#include<cstdio>
int main(){
    int k, n, s, p;
    scanf("%d %d %d %d", &k, &n, &s, &p);
    printf("%d", (n / s + !!(n % s)) * k / p  + !!(((n / s + !!(n % s)) * k) % p));
}