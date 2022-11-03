#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const li INF = 1e18;
const int M = 1e9 + 7;
const int N = 2e5 + 13;

/*
5 10
99.99
*/

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    string s;
    cin >> s;

    int x = 0, y = 0;

    for(auto c : s) {
        if(c == 'L')
            x--;
        else if(c == 'R')
            x++;
        else if(c == 'U')
            y++;
        else
            y--;
    }

    x = abs(x), y = abs(y);

    if((x + y) % 2 > 0) {
        cout << -1 << endl;
    } else
        cout << (x + y) / 2 << endl;
}