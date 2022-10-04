#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <ctime>
#include <random>
#include <cmath>
#include <bitset>
#include <iomanip>
#include <list>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    string s;
    cin >> s;
    int n;
    cin >> n;
    vector <string> a(n);
    bool hb = 0, he = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == s) {
            cout << "YES\n";
            return 0;
        }
        if (a[i][0] == s[1]) he = 1;
        if (a[i][1] == s[0]) hb = 1;
    }
    if (he && hb) {
        cout << "YES\n";
        return 0;
    }
    cout << "NO\n";
}