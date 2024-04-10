#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using vvi = vector<vector<int>>;

const li INF = 1e18;
const int M = 1e9 + 7;
const int N = 1e6 + 13;


/*

*/

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    map<int, int> mp;
    for(int i = 2; i * 1ll * i <= k; i++) {
        if(k % i == 0) {
            while(k % i == 0) {
                k /= i;
                mp[i]++;
            }
        }
    }

    if(k > 1)
        mp[k]++;

    set<int> st;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;

        for(auto p : mp) {
            int cnt = 0;
            while(x % p.f == 0) {
                x /= p.f;
                cnt++;
            }
            if(cnt >= p.s) {
                st.insert(p.f);
            }
        }
    }

    cout << (st.size() == mp.size() ? "Yes" : "No") << endl;

}