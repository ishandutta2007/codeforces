#include <iostream>
#include <algorithm>
#include <cstdio>
#include <sstream>
#include <set>
#include <cmath>

using namespace std;


int n;
int a[100000];


int gcd(int a, int b) {
    if (a == 0) {
        return b;
    }
    return gcd(b % a, a);
}


int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    int p = a[0];
    for (int j = 0; j < n; j++) {
        p = gcd(p, a[j]);
    }
    if ((a[n - 1] / p - n) % 2 == 1) {
        cout << "Alice" << endl;
    } else {
        cout << "Bob" << endl;
    }
    return 0;
}