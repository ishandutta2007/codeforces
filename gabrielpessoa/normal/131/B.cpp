#include <bits/stdc++.h>
using namespace std;

    
long long int arrP[11];
long long int arrN[11];

int main() {
    int temp, n;
    long long int resposta;
    cin >> n;
    while(n--) {
        cin >> temp;
        if(temp >= 0) {
            arrP[temp]++;
        }
        if(temp <= 0) {
            arrN[temp * -1]++;
        }
    }
    resposta = arrP[0] * (arrN[0] - 1) / 2;
    for(int i = 1; i <= 10; i++) {
        resposta += arrP[i] * arrN[i];
    }
    cout << resposta;
    return 0;
}