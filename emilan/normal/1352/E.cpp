#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        map<int, int> m;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            m[a[i]]++;
        }

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            int sum = a[i];
            for (int j = i + 1; j < n; j++) {
                sum += a[j];
                if (m.count(sum)) {
                    cnt += m[sum];
                    m.erase(sum);
                }
            }
        }

        cout << cnt << '\n';
    }

    return 0;
}