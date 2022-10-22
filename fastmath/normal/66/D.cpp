#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 10001;

bool pr[MAXN];
vector <int> v;
void calc() {
    for (int i = 0; i < MAXN; ++i) pr[i] = 1;
    for (int i = 2; i < MAXN; ++i) {
        if (pr[i]) {
            for (int j = i * 2; j < MAXN; j += i) pr[j] = 0;
            v.push_back(i);
        }
    }
}

int a[MAXN];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    if (n == 2) {
        cout << "-1\n";
        exit(0);
    }
    
    for (int i = 0; i < n; ++i) a[i] = 1;
    for (int i = 0; i < n - 1; ++i) a[i] *= 2;
    for (int i = 1; i < n; ++i) a[i] *= 3;
    a[0] *= 5;
    a[n - 1] *= 5;
    
    calc();
    for (int i = 0; i < n; ++i) a[i] *= v[i + 3];

    for (int i = 0; i < n; ++i) cout << a[i] << '\n';

    return 0;
}