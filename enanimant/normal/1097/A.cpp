// January 4, 2019
//

/*

*/


#include <bits/stdc++.h>

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("debug_output.txt", "w", stderr);
#endif


    string table;
    cin >> table;
    for (int i = 0; i < 5; i++) {
        string hand;
        cin >> hand;
        if (hand[0] == table[0] || hand[1] == table[1]) {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";


    return 0;
}