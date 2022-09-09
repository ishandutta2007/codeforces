#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    for (cin >> t; t; t -= 1) {
        string n;
        cin >> n;
        if (ranges::count_if(n, [&](char c){
            return c % 2 == 0;
        }) == 0)
            cout << "-1\n";
        else if (n.back() % 2 == 0) cout << "0\n";
        else if (n[0] % 2 == 0) cout << "1\n";
        else cout << "2\n";
    }
    return 0;
}