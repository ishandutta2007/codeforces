#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, total = 0, a, b, c;
    cin >> n;
    while(n--) {
        cin >> a >> b >> c;
        if(a + b + c > 1) {
            total++;
        }
    }
    cout << total;
    return 0;
}