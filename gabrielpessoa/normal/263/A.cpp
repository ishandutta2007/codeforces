#include <bits/stdc++.h>
using namespace std;

int main() {
    int a;
    for(int i = 1; i<= 5; i++) {
        for(int j = 1; j <= 5; j++) {
            cin >> a;
            if(a == 1) {
                printf("%d", abs(i-3) + abs(j-3));
            }
        }
    }
    return 0;
}