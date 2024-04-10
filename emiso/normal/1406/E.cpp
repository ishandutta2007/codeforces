#include <bits/stdc++.h>

using namespace std;

int n, ok[100010], zero, N, sum;

int A(int x) {
    printf("A %d\n", x);
    fflush(stdout);
    int ret;
    scanf("%d", &ret);
    return ret;
}
int B(int x) {
    printf("B %d\n", x);
    fflush(stdout);
    int ret;
    scanf("%d", &ret);
    return ret;
}
void C(int x) {
    printf("C %d\n", x);
    fflush(stdout);
    exit(0);
}
int find(int j) {
    long long temp = j;
    while(temp * j <= n && A(temp * j)) temp *= j;
    return temp;
}

int main() {
    memset(ok, 0x7f, sizeof ok);
    scanf("%d", &n); N = n;
    int MAGIC = 100;
    vector<int> temp, factors;
    auto check = [&](){
        int val = A(1);
        if(val != N - sum)
            for(int j : temp)
                if(A(j))
                    factors.push_back(find(j));
        temp.clear();
        N = val;
        sum = 0;
    };
    for(int i = 2; i <= n; i++) {
        if(!ok[i]) continue;
        for(int p = i; p <= n; p += i) ok[p] = 0;
        sum += B(i);
        temp.push_back(i);
        if(temp.size() == MAGIC) check();
    }
    if(!temp.empty()) check();
    int ans = 1;
    for(int x : factors) ans *= x;
    C(ans);
    return 0;
}