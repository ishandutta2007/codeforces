#include <bits/stdc++.h>
using namespace std;

const int maxn = 10010;
int n, K, a[maxn], b[maxn], x[maxn];
bool ok[31];

int main() {
    cin >> n >> K;
    for (int i = 2; i <= n; i++) {
        cout << "or " << 1 << " " << i << endl;
        cin >> a[i];
        cout << "and " << 1 << " " << i << endl;
        cin >> b[i];
        x[i] = a[i] - b[i];
    }
    vector<int> V;
    int t = b[2];
    for (int i = 0; i < 30; i++) {
        if ((b[2] >> i & 1) || !(a[2] >> i & 1)) ok[i] = 1;
    }
    cout << "or 2 3" << endl;
    int y; cin >> y;
    for (int i = 0; i < 30; i++) if (!ok[i]) {
        if (x[3] >> i & 1) {
            if (!(y >> i & 1)) t |= 1 << i;
        } else {
            if (a[3] >> i & 1) t |= 1 << i;
        }
    }
    V.push_back(t);
    for (int i = 2; i <= n; i++) {
        V.push_back(t ^ x[i]);
    }
    sort(V.begin(), V.end());
    cout << "finish " << V[K - 1] << endl;
    return 0;
}