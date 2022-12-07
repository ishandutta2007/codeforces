#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const int N = 10000;

int d[N];
int n;

bool isPrime(int n) {
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    cin >> n;
    d[2] = 1;
    for (int i = 3; i < N; ++i) {
        d[i] = i - 1;
        while (i % d[i] != 0) {
            --d[i];
        }
        for (int j = 2; j <= i - 2; ++j) {
            d[i] = min(d[i], d[j] + d[i - j]);
        }
    }

    if (n < N) {
        cout << d[n] << endl;
        return 0;
    }

    if (isPrime(n)) {
        cout << 1 << endl;
        return 0;
    }

    if (isPrime(n - 2)) {
        cout << 2 << endl;
        return 0;
    }

//    for (int i = 1; i < N; ++i) {
//        if (!(i % 2 != 0 || d[i] == 2)) cout << i << ": " << d[i] << endl;
//        if (!(i % 2 != 1 || d[i] <= 3))  cout << i << ": " << d[i] << endl;
//    }

    if (n % 2 == 0) {
        cout << 2 << endl;
    } else {
        cout << 3 << endl;
    }
    return 0;
}