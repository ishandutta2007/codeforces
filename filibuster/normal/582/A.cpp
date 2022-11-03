#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9;
const int M = 1e9 + 7;
const int N = 2e5 + 13;

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int n;
    cin >> n;

    map<int, int> mp;
    for(int i = 0; i < n * n; i++) {
        int x;
        cin >> x;

        mp[-x]++;
    }

    vector<int> b;
    while(!mp.empty()) {
        int x = -mp.begin()->f;
//        cout << x << endl;
        for(auto y : b) {
            int g = -__gcd(y, x);
            mp[g]--;
            if(mp[g] == 0)
                mp.erase(g);
        }

        b.push_back(x);
        for(auto y : b) {
            int g = -__gcd(y, x);
            mp[g]--;
            if(mp[g] == 0)
                mp.erase(g);
        }
    }

    for(auto x : b)
        cout << x << ' ';
}