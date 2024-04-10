#include <bits/stdc++.h>

using namespace std;

int main() {
    double n;
    cin >> n;
    
    int pos = 0, neg = 0;
    for (int i = 0; i < n-.0001; i++) {
        int z;
        cin >> z;
        if (z > 0) pos++;
        if (z < 0) neg++;
    }
    
    if (pos>=ceil(n/2)) {
        cout << 1 << endl;
    } else if (neg>=ceil(n/2)) {
        cout << -1 << endl;
    } else {
        cout << 0 << endl;
    }
}