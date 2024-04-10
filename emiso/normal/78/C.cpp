#include <bits/stdc++.h>

using namespace std;

bool solve(int n, int m, int k){
    for(int i=1;i*i<=n; i++) {
        if(n % i == 0) {
            if(n / i >= k && i > 1)
                return true;
            if(i >= k && (n / i) > 1)
                return true;
        }
    }
    return false;
}

int main() {
    int n, m, k;
    scanf("%d %d %d", &m, &n, &k);
    m %= 2;
    if(n < k || !m) printf("Marsel\n");
    else if(m) printf("%s\n",(solve(n, m, k)) ? "Timur" : "Marsel");

    return 0;
}