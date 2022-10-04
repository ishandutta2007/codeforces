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

int a;

int count(int sz) {
    int cnt = sz / (a + 1);
    sz -= cnt * (a + 1);
    return cnt + (sz == a);
}

vector <int> p, gsz;

void init(int a) {
    p[a] = a;
    gsz[a] = 1;
}

int get(int a) {
    if (a == p[a]) return a;
    else return p[a] = get(p[a]);
}

void merge(int a, int b) {
    a = get(a);
    b = get(b);
    if (a != b) {
        if (gsz[a] < gsz[b]) swap(a, b);
        p[b] = a;
        gsz[a] += gsz[b];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k >> a;
    p.resize(n);
    gsz.resize(n);
    for (int i = 0; i < n; ++i) {
        init(i);
    }
    int m;
    cin >> m;
    vector <int> x(m);
    for (int i = 0; i < m; ++i) {
        cin >> x[i];
        --x[i];
    }
    vector <int> f(n);
    for (int i = 0; i < m; ++i) {
        f[x[i]] = 1;
    }
    int cnt = 0;
    for (int i = 0; i < n; ++i){
        if (f[i] == 0 && (i == n - 1 || f[i + 1] == 1)) {
            int j = i;
            while (j >= 0 && !f[j]) {
                merge(i, j);
                --j;
            }
            ++j;
            cnt += count(i - j + 1);
        }
    }
    if (cnt >= k) {
        cout << -1 << '\n';
        return 0;
    }
    for (int i = m - 1; i >= 0; --i) {
        f[x[i]] = 0;
        if (x[i]) {
            if (f[x[i] - 1] == 0) {
                cnt -= count(gsz[get(x[i] - 1)]);
                merge(x[i], x[i] - 1);
            }
        }
        if (x[i] != n - 1) {
            if (f[x[i] + 1] == 0) {
                cnt -= count(gsz[get(x[i] + 1)]);
                merge(x[i], x[i] + 1);
            }
        }
        cnt += count(gsz[get(x[i])]);
        if (cnt >= k) {
            cout << i + 1 << '\n';
            return 0;
        }
    }
}