#include <bits/stdc++.h>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    for(int i = 0; i < a.length(); i++) {
        a[i] = tolower(a[i]);
        b[i] = tolower(b[i]);
    }
    if(a > b) {
        puts("1");
    } else if(a < b) {
        puts("-1");
    } else {
        puts("0");
    }
    return 0;
}