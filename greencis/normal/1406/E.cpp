#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = int64_t;

int query(char c, int x) {
    cout << c << ' ' << x << endl;
    if (c == 'C') exit(0);
    int ans;
    cin >> ans;
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> primes;
    for (int i = 2; i <= n; ++i) {
        bool good = true;
        for (int x : primes) {
            if (i % x == 0) {
                good = 0;
                break;
            }
        }
        if (good) primes.push_back(i);
    }
    int ans = 1;
    for (int x : primes) {
        if (x * x > n)
            break;
        query('B', x);
        for (ll deg = x; deg <= n; deg *= x)
            if (query('A', deg))
                ans *= x;
            else break;
    }

    reverse(all(primes));
    while (!primes.empty() && primes.back() * primes.back() <= n)
        primes.pop_back();
    reverse(all(primes));

    if (ans == 1) {
        if (!primes.empty()) {
            const int K = sqrt(primes.size());
            int left_numbers = primes.size() + 1;
            for (int block = 0; block * K < (int)primes.size(); ++block) {
                int R = min((int)primes.size(), (block + 1) * K);
                int L = block * K;
                for (int i = L; i < R; ++i)
                    query('B', primes[i]);
                left_numbers -= R - L;
                if (query('A', 1) != left_numbers) {
                    for (int i = L; i < R; ++i) {
                        if (query('A', primes[i])) {
                            ans = primes[i];
                            break;
                        }
                    }
                    break;
                }
            }
        }
    } else {
        for (int x : primes) {
            if (ans * (ll)x <= n && query('A', ans * x)) {
                ans *= x;
                break;
            }
        }
    }
    query('C', ans);
}