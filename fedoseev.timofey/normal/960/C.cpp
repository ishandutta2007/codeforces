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

const int mx = 1e4;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int x, d;
    cin >> x >> d;
    vector <int> st;
    while (x) {
        int j = 0;
        while (((1 << j) - 1) <= x) ++j;
        --j;
        st.push_back(j);
        x -= ((1 << j) - 1);
    }
    int cnt = 0;
    for (int i = 0; i < st.size(); ++i) {
        cnt += st[i];
    }
    if (cnt > mx) {
        cout << -1 << "\n";
        return 0;
    }
    vector <ll> ans;
    ll cur = 1;
    for (int i = 0; i < st.size(); ++i) {
        for (int j = 0; j < st[i]; ++j) {
            ans.push_back(cur);
        }
        cur += d;
    }
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << " ";
    }
    cout << "\n";
}