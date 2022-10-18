#include <iostream>
#include <cmath>
using namespace std;

int n,m;

bool isPrime(int num) {
    int sq = sqrt(num);
    for (int i = 2; i <= sq; ++i) {    
        if (num % i == 0) return false;
    } return true;
}

int main() {
    cin >> n >> m;
    if (!isPrime(n) || !isPrime(m)) { cout << "NO"; return 0; }
    int q = n+1;
    while (!isPrime(q)) ++q;
    cout << (q == m ? "YES":"NO");
    return 0;
}