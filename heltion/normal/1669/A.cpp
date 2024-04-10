#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int rating;
        cin >> rating;
        cout << "Division " << 4 - (rating >= 1400) - (rating >= 1600) - (rating >= 1900) << "\n";
    }
}