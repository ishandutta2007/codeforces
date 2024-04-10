#include <bits/stdc++.h>

#define MN 15000100

using namespace std;
typedef long long ll;

ll n, ans, a[MN], g;
int divisor[MN], freq[MN];

void modified_sieve() {
    for(int i = 1; i < MN; i++)
        divisor[i] = i;

    for(int i = 2; i * i < MN; i++)
        if(divisor[i] == i)
            for(int j = 2*i; j < MN; j += i)
                divisor[j] = i;
}

void get_prime_divisors(int x) {
    vector<int> ret;
    while(x != 1) {
        ret.push_back(divisor[x]);
        x /= divisor[x];
    }
    reverse(ret.begin(), ret.end());
    ret.resize(unique(ret.begin(), ret.end()) - ret.begin());
    for(int x : ret) freq[x]++;
}

int main() {
    modified_sieve();
    scanf("%lld", &n);

    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        if(g == 0) g = a[i];
        else g = __gcd(g, a[i]);
    }
    for(int i = 0; i < n; i++) {
        a[i] /= g;
        get_prime_divisors(a[i]);
    }
    int maxi = 0;
    for(int i = 0; i < MN; i++) {
        maxi = max(maxi, freq[i]);    
    }

    if(maxi == 0) puts("-1");
    else printf("%lld\n", n - maxi);
    return 0;
}