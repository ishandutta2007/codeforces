#include <bits/stdc++.h>
using namespace std;

int arr[105];

int main() {
    int n, k, x, soma = 0;
    cin >> n >> k >> x;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for(int i = n - 1; i >= 0; i--) {
        if(arr[i] < x) {
            break;
        }
        arr[i] = x;
        if(--k == 0) {
            break;
        }
    }
    for(int i = 0; i < n; i++) {
        soma += arr[i];
    }
    cout << soma << endl;
    return 0;
}