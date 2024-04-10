#include <bits/stdc++.h>

#define rep(a, s, b)   for(int a = (s); a < (b); ++a)
#define trav(a, b)   for(auto& a : (b))
#define debug(x)    clog << #x << " = " << x << endl;
#define all(a)      (a).begin(),(a).end()
#define endl        '\n'
#define tests int _testsvariableXXX; cin >> _testsvariableXXX; while (_testsvariableXXX--)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;

int main(int argc, char *argv[]) {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);


    //content
    int n, m;
    cin >> n >> m;
    if (m < n-1) {
        cout << "Impossible" << endl;
        return 0;
    }
    if (n < 4000) {
        vector<pair<int, int>> edges;
        rep(i, 1, n + 1) rep(j, i + 1, n + 1) {
                if (gcd(i, j) == 1) edges.emplace_back(i, j);
            }
        if (edges.size() >= m) {
            cout << "Possible" << endl;
            for (int i = 0; i < m; i++) {
                cout << edges[i].first << ' ' << edges[i].second << endl;
            }
        } else {
            cout << "Impossible" << endl;
        }
    } else {
        cout << "Possible" << endl;
        vector<int> primes = {1};
        for (int p = 2; p < 5000; p++) {
            bool prime = true;
            for (int i = 2; i * i <= p; i++) {
                if (p % i == 0)
                    prime = false;
            }
            if (prime) primes.push_back(p);
        }
        int c = 0;
        for (int pt = 0; pt < primes.size(); pt++) {
            int p = primes[pt];
            for (int i = p+1; c < m && i <= n; i++) {
                if (p== 1 ||i % p != 0) {
                    cout << p << ' ' << i <<endl;
                    c++;
                }
            }
        }
    }


    cout.flush();
    return 0;
}