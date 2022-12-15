#include <bits/stdc++.h>
using namespace std;

int main() {
    long long g, l, r, x, m, menor, resposta = -1;
    cin >> g;
    l = g;
    r = g * 8;
    while(l <= r) {
        m = (l+r)/2;
        menor = 0;
        x = 0;
        for(long long i = 2; i <= cbrt(m); i++) {
            x += m / (i * i * i);
            menor = max(menor, m - m % (i * i * i));
            //cout << "X e I: " << x << " " << i << endl;
        }
        //cout << "X e M: " << x << " " << m << endl;
        if(g == x) {
            resposta = menor;
            break;
        } else if(g < x) {
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    cout << resposta << endl;
    
    return 0;
}