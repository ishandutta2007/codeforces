#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    int minDif = -1;
    int ordem[8] = {0, 1, 2, 3, 4, 5, 6, 7};
    char arr[8][10];
    char temp[10];
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    do {
        int menor = -1, maior = 0;
        for(int i = 0; i < n; i++) {
            temp[k] = arr[i][k];
            for(int j = 0; j < k; j++) {
                temp[j] = arr[i][ordem[j]];
            }
            int valorString = stoi(temp);
            if(menor == -1) {
                menor = valorString;
                maior = valorString;
            } else {
                menor = min(valorString, menor);
                maior = max(valorString, maior);
            }
        }
        if(minDif == -1) {
            minDif = maior - menor;
        } else {
            minDif = min(minDif, maior - menor);
        }
    } while(next_permutation(ordem, ordem+k));
    cout << minDif;
    return 0;
}