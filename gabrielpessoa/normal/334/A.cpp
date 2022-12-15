#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = i*(n/2); j < (i+1)*(n/2); j++) {
            cout << j + 1<< " " << n*n - j << " ";
        }
        cout << endl;
    }
    return 0;
}