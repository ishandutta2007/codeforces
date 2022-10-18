#include <cstdio>
#include <iostream>
#include <algorithm>
unsigned long long n, m, k; 
void judge(long long k) {
    for (long long i=k/std::max(n, m);i*i<=k;++i) {
        if (i==0) continue;
        if (k%i==0&&((i<=n&&k/i<=m)||(k/i<=n&&i<=m))) {
            if (k/i>n) i=k/i;
            std::cout << "YES" << std::endl <<0<<" "<<0<<std::endl<<0<<" "<<i<<std::endl<<k/i<<" "<<0<<std::endl;
            return;
        }
    }std::cout << "NO";
}

int main() {
    std::cin>>n>>m>>k;
    if (n*m*2%k!=0) {printf("NO"); return 0;}
    long long p=n*m*2/k;
    judge(p);
    return 0;
}