#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cassert>
#include <map>
#include <numeric>
#include <cstring>
#include <set>
#include <ctime>
#include <queue>
#include <cmath>
#include <iomanip>
#include <iterator>
#include <bitset>
#include <unordered_map>
#include <complex>
#include <unordered_set>
#include <chrono>
#include <random>

using namespace std;
using namespace std::chrono;

const int MAXN = 100000;
const int MAXP = 200000;

int v[1 + MAXN];
bool notPrime[1 + MAXP];
vector<int> primes;

void precompute() {
    for (int i = 2; i <= MAXP; i++) {
        if (!notPrime[i]) {
            primes.push_back(i);
            for (int j = 2 * i; j <= MAXP; j += i) {
                notPrime[j] = true;
            }
        }
    }
}

int main() {
    // ifstream cin("input.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    auto start = high_resolution_clock::now();

    precompute();
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        long long n;
        cin >> n;
        long long p = 2;
        while (n % 2 == 0) {
            n /= 2;
            p *= 2;
        }
        if (n >= p + 1) {
            cout << p << "\n";
        } else if (n != 1) {
            cout << n << "\n";
        } else {
            cout << "-1\n";
        }
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
//    cout << duration.count() << "\n";
    return 0;
}