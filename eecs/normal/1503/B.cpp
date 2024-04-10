#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    cin >> n;
    vector<pair<int, int>> V1, V2;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if ((i + j) & 1) V1.emplace_back(i, j);
            else V2.emplace_back(i, j);
        }
    }
    int p1 = 0, p2 = 0;
    for (int i = 1; i <= n * n; i++) {
        int x; cin >> x;
        if (x != 3) {
            if (p2 < V2.size()) {
                cout << 3 << " " << V2[p2].first << " " << V2[p2].second << endl;
                p2++;
            } else {
                cout << (x == 1 ? 2 : 1) << " " << V1[p1].first << " " << V1[p1].second << endl;
                p1++;
            }
        } else {
            if (p1 < V1.size()) {
                cout << 1 << " " << V1[p1].first << " " << V1[p1].second << endl;
                p1++;
            } else {
                cout << 2 << " " << V2[p2].first << " " << V2[p2].second << endl;
                p2++;
            }
        }
    }
    return 0;
}