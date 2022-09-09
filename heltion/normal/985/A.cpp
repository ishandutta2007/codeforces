#include<bits/stdc++.h>
int main(){
    int n, odd = 0, even = 0;
    scanf("%d", &n);
    int *p = new int[n / 2];
    for(int i = 0; i < n / 2; i += 1) scanf("%d", p + i);
    std::sort(p, p + n / 2);
    for(int i = 0; i < n / 2; i += 1)
        odd += abs(2 * i + 1 - p[i]), even += abs(2 * i + 2 - p[i]);
    printf("%d", std::min(odd, even));
}