#include <iostream>
#include <stdlib.h>

using namespace std;

int main(){
    
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        if (m % 2 == 0){
            if ((i % m) % 2 == 0) cout << m / 2 - (i % m) / 2 << "\n"; else cout << m / 2 + 1 + (i % m) / 2 << "\n";
        } else {
            if ((i % m) % 2 == 0) cout << m / 2 + 1 + (i % m) / 2 << "\n"; else cout << m / 2 - (i % m) / 2 << "\n";
        }
    }
    
    return 0;
}