#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    for (cin >> t; t; t -= 1) {
        int a, b;
        cin >> a >> b;
        cout << min({(a + b) / 4, a, b}) << "\n";
    }
    return 0;
}