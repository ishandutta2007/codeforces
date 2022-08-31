#include <cmath>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

using std::vector;
using std::pair;
using std::make_pair;
using std::min;
using std::max;
using std::cin;
using std::cout;

bool isPrime(long long i) {
    bool result = true;
    for (long long j = 2; j * j <= i; ++j) {
        if (i % j == 0) {
            result = false;    
            break;
        }
    }
    return result;
}

vector <long long> genPrimes(long long n) {
    vector <long long> primes;
    for (long long i = 2; i <= n; ++i) {
        if (isPrime(i)) {
            primes.push_back(i);
        }
    }
    return primes;
}

long long minD(long long n, int i, const vector<long long> &primes) {
    if (n < primes[i]) {
        return 0;
    }
    long long result = n / primes[i];
    for (int j = i - 1; j >= 0; --j) {
        result -= minD(n / primes[i], j, primes);
    }
    return result;
}

long long q(long long k, long long n) {
    if (k > n) {
        return 0;
    }
    if (k * k > n) {
        return 1;
    }
    vector <long long> primes = genPrimes(k);
    return minD(n, primes.size() - 1, primes);
}

int main() {
    long long a, b, k;
    cin >> a >> b >> k;
    if (!isPrime(k)) {
        cout << 0 << '\n';
        return 0;
    }
    cout << q(k, b) - q(k, a - 1) << '\n';
    return 0;
}