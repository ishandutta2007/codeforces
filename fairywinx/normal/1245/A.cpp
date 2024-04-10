#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <set>
#include <unordered_map>

using namespace std;

int gcd(int a, int b) {
    if (a == 0) return b;
    return gcd(b % a, a);
}

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        if (gcd(a, b) == 1) cout << "Finite" << '\n';
        else cout << "Infinite" << '\n';
    }
}