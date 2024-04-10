#include <bits/stdc++.h>

#define MN 1000100

using namespace std;

int divisor[MN], n, k;

void modified_sieve() {
    for(int i = 1; i < MN; i++)
        divisor[i] = i;

    for(int i = 2; i < MN; i++)
        if(divisor[i] == i)
            for(int j = 2*i; j < MN; j += i)
                divisor[j] = i;
}

vector<int> get_prime_divisors(int x) {
    vector<int> ret;
    while(x != 1) {
        ret.push_back(divisor[x]);
        x /= divisor[x];
    }

    reverse(ret.begin(), ret.end());
    return ret;
}

int main() {
    modified_sieve();

    scanf("%d %d", &n, &k);

    vector<int> divs = get_prime_divisors(n);

    if(divs.size() < k) {
        printf("-1\n");
        return 0;
    }

    while(divs.size() > k) {
        int x = divs.back();
        divs.pop_back();

        x = divs.back() * x;
        divs.pop_back();

        divs.push_back(x);
    }

    for(int divi : divs)
        printf("%d ", divi);
    puts("");

    return 0;
}