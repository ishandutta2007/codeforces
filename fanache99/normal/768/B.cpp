//#include <fstream>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>

using namespace std;

//ifstream cin("tema.in");
//ofstream cout("tema.out");

const int MAXLOG = 50;

long long v[1 + MAXLOG];
int limit;

void Compute(long long n, int where) {
    if (n == 0 || n == 1) {
        v[where] = 1;
        limit = where;
        return;
    }
    Compute(n / 2, where + 1);
    v[where] = 2 * v[where + 1] + 1;
}

int Get(long long x, long long n) {
    for (int i = 0; i < limit; i++, n /= 2) {
        if (x == v[i + 1] + 1)
            return n % 2;
        if (x > v[i + 1] + 1)
            x -= (v[i + 1] + 1);
    }
    return n;
}

int main() {
    long long n, l, r;
    cin >> n >> l >> r;
    Compute(n, 0);
    int answer = 0;
    for (long long i = l; i <= r; i++)
        answer += Get(i, n);
    cout << answer << "\n";
    return 0;
}