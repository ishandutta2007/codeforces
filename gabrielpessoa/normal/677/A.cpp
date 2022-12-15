#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, h;
    cin >> n >> h;
    int resposta = n;
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if(a > h) {
            resposta++;
        }
    }
    cout << resposta;
    return 0;
}