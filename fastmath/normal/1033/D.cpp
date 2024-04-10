#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MOD = 998244353;

int mod(int n) {
    return (n % MOD + MOD) % MOD;
}

const int MAXN = 507;

int n;
map <int, int> a;

void read() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        ++a[x];
    }
}

const int INF = 1e9 + 7;

bool check(int n) {
    int t = round(sqrt(n));
    return t * t == n;
}

int msqrt(int n) {
    return round(sqrt(n));
}

const int CINF = 1e6 + 7;

bool cubecheck(int n) {
    int t = round(pow(n, 1.0/3));
    return t * t * t == n; 
}

int cube(int n) {
    return round(pow(n, 1.0/3));
}

vector <int> v;
map <int, int> d;
void solve() {
    for (auto e : a) {
        int val = e.first;
        if (check(val)) {
            int t = msqrt(val);
            if (check(t)) d[msqrt(t)] += 4 * e.second;
            else d[t] += 2 * e.second;
        }   
        else if (cubecheck(val)) {
            d[cube(val)] += 3 * e.second;
        }
        else {
            int p = -1, q = -1;
            for (auto ne : a) {
                if (ne.first == val) continue;
                int d = __gcd(val, ne.first);
                if (d != 1) {
                    p = d;
                    q = val / d;
                    break;
                }
            }
            if (p != -1) {
                d[p] += e.second;
                d[q] += e.second;
            }       
            else {
                v.push_back(e.second);
                v.push_back(e.second);
            }
        }
    }
}

void print() {
    int ans = 1;
    for (auto e : d) ans = mod(ans * (e.second + 1));
    for (int e : v) ans = mod(ans * (e + 1));
    cout << ans << '\n';
    fflush(stdout);
}   

signed main() {
    read();
    solve();
    print();
    return 0;
}