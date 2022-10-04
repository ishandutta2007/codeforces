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
#include <unordered_set>
#include <unordered_map>
#include <cassert>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
    ios_base::sync_with_stdio(false); cout.setf(ios::fixed); cout.precision(20); cin.tie(0);
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector <int> st;
    vector <int> pr(n);
    vector <int> used(n);
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '(') st.push_back(i);
        else {
            pr[i] = st.back();
            pr[st.back()] = i;
            st.pop_back();
        }
    }
    int uk = 0;
    while (n > k) {
        while (used[uk]) ++uk;
        used[uk] = 1;
        used[pr[uk]] = 1;
        n -= 2;
    }
    for (int i = 0; i < s.size(); ++i) {
        if (!used[i]) {
            cout << s[i];
        }
    }
}