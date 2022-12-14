#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string win;
    cin >> n >> win;

    if (count(begin(win), end(win), 'A') > n / 2)
        cout << "Anton";
    else if (count(begin(win), end(win), 'D') > n / 2)
        cout << "Danik";
    else
        cout << "Friendship";
    
    return 0;
}