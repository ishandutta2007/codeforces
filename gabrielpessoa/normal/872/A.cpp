#include <bits/stdc++.h>
using namespace std;

int a[20];
int b[20];

int main() {
    int n, m;
    int menor = 10;
    int menorA = 10;
    int menorB = 10;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        menorA = min(menorA, a[i]);
    }
    for(int i = 0; i < m; i++) {
        cin >> b[i];
        menorB = min(menorB, b[i]);
        for(int j = 0; j < n; j++) {
            if(b[i] == a[j]) {
                menor = min(menor, b[i]);
            }
        }
    }
    if(menor < 10) {
        cout << menor;
    } else {
        cout << min(menorA, menorB) << max(menorA, menorB);
    }
    return 0;
}