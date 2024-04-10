#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int resposta = ((n-1)/2)/m + 1;
    if(resposta*m > n) {
        cout << -1;
    } else {
        cout << resposta * m;
    }
    return 0;
}