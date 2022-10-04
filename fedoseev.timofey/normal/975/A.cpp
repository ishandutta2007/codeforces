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
    int n;
    cin >> n;
    set <vector <bool>> ck;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        vector <bool> have(26);
        for (auto c : s) {
            have[c - 'a'] = 1;
        }
        ck.insert(have);
    }
    cout << ck.size() << '\n';
}