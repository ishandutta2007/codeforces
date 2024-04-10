#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

char inp[1000];

long long pot = 1;
const int mod = 1000000007;
const int inv = (mod+1)/2;
long long ans = 0;

int main() {
    scanf("%s", inp);
    int n = strlen(inp);

    for (int i = 1; i < n; i++) {
        pot = (pot * 2) % mod;
    }

    pot = (pot * pot) % mod;

    //cout << pot << " " << n << endl;
    for (int i = 0; i < n; i++) {
        if (inp[i] =='1') ans = (ans + pot) % mod;
        pot = (pot * inv) % mod;
    }

    std::cout << ans << std::endl;
}