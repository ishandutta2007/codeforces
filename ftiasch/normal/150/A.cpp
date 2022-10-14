// Codeforces Round #107 
// Problem A -- Win or Freeze
#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

vector <long long> factor(long long n) {
    vector <long long> result;
    for (long long i = 2; i * i <= n; ++ i) {
        while (n % i == 0) {
            n /= i;
            result.push_back(i);
        }
    }
    if (n > 1) {
        result.push_back(n);
    }
    return result;
}

int main() {
    long long n;
    cin >> n;
    vector <long long> divisors = factor(n);
    if ((int)divisors.size() <= 1) {
        puts("1");
        puts("0");
    } else if ((int)divisors.size() == 2) {
        puts("2");
    } else {
        puts("1");
        long long result = 1;
        for (int i = 2; i < (int)divisors.size(); ++ i) {
            result *= divisors[i - 2];
        }
        cout << n / result << endl;
    }
    return 0;
}