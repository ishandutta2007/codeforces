#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>

#define int long long
#define all(x) x.begin(), x.end()
#define pb emplace_back
#define mp make_pair

using namespace std;

void setup() {
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
    ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    #endif

    srand(time(NULL));
}

signed main() {
    setup();
    
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    if (x1 == x2 || y1 == y2)
        cout << 1 << ' ';
    else 
        cout << 2 << ' ';

    if ((x1 + y1) % 2 != (x2 + y2) % 2) 
        cout << 0 << ' ';
    else if (abs(x2 - x1) == abs(y2 - y1)) 
        cout << 1 << ' ';
    else 
        cout << 2 << ' ';

    cout << abs(x1 - x2) + abs(y1 - y2) - min(abs(x1 - x2), abs(y1 - y2)); 
}