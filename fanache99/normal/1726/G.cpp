#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

#define MOD 998244353

using namespace std;

vector<pair<int, int>> bucurii;

long long fact[200010];
int bucurie[200010], dir[200010];

map<pair<int, int>, int> b_counts;

long long sol = 1;

long long put(long long x, int p) {
    if (p == 1) {
        return x;
    }
    if (p & 1) {
        return (put((x * x) % MOD, p >> 1) % MOD * x) % MOD;
    } else {
        return put((x * x) % MOD, p >> 1) % MOD;
    }
}

long long inv(int k) {
    return put(k, MOD - 2);
}

void arr(int n, int k) {
    sol = (((sol * fact[n]) % MOD) * inv(fact[k])) % MOD;
}

int main() {
    int n;
    cin >> n;

    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }

    for (int i = 0; i < n; i++) {
        cin >> bucurie[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> dir[i];
    }
    for (int i = 0; i < n; i++) {
        bucurii.push_back(make_pair(bucurie[i], dir[i]));
    }

    sort(bucurii.begin(), bucurii.end());
    
    if (bucurii[0].first == bucurii.back().first) {
        int sol = 1;
        for (int i = 2; i <= n; i++) {
            sol = 1LL * sol * i % MOD;
        }
        cout << sol;
        return 0;
    }

    int mf = bucurii.back().first;

    if (bucurii.front().second == 0 && bucurii.front().first != mf) {
        cout << 0 << "\n";
        return 0;
    }

    int target = bucurii.front().first + n - 1;
    long long places = n;

    for (auto[x, y]: bucurii) {
        b_counts[make_pair(x, y)]++;
    }

    int places_left = n;
    for (auto it = b_counts.rbegin(); it != b_counts.rend(); it++) {
        int urc = target - it->first.first;
        if (it->first.second == 1 && it->first.first == target) {
            arr(places_left, places_left - it->second);
        } else if (it->first.second == 1) {
            if (it->second > 1) {
                cout << 0;

                return 0;
            }
        } else {
            if (urc > places_left - it->second) {
                cout << 0;

                return 0;
            }
            arr(it->second, 1);
        }
        places_left -= it->second;
    }
    cout << sol;

    return 0;
}