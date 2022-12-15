#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, anterior, proximo, grupos = 1;
    cin >> n >> anterior;
    for(int i = 1; i < n; i++) {
        cin >> proximo;
        if(proximo != anterior) {
            anterior = proximo;
            grupos++;
        }
    }
    cout << grupos;
    return 0;
}