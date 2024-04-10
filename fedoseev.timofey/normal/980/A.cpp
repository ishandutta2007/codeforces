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
    map <char, int> cnt;
    for (auto c : s) {
        ++cnt[c];
    }
    if (cnt['o'] == 0) {
        cout << "YES\n";
        return 0;
    }
    if (cnt['-'] % cnt['o'] == 0) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
}