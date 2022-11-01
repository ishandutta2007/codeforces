#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

string str = "codeforces";
ll n, ans, a[MN], tot = 1;

int main() {
    scanf("%lld", &n);

    for(int i = 0; i < 10; i++) {
        a[i] = 1;
    }
    while(tot < n) {
        int idx = 0;
        for(int i = 1; i < 10; i++)
            if(a[i] < a[idx])
                idx = i;

        tot /= a[idx];
        a[idx]++;
        tot *= a[idx];
    }

    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < a[i]; j++) {
            printf("%c", str[i]);
        }
    }
    puts("");

    return 0;
}