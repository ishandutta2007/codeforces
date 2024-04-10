#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1){
        int n;
        cin >> n;
        vector<int> cnt(n + 1), a(n), b;
        for (int& ai : a) {
            cin >> ai;
            cnt[ai] += 1;
        }
        for (int i = 0, j = 0; i < n; i = j) {
            int k = 0;
            while (cnt[k]) k += 1;
            int m = 0;
            set<int> s;
            while (true) {
                cnt[a[j]] -= 1;
                s.insert(a[j ++]);
                while (s.count(m)) m += 1;
                if (m == k) break;
            }
            b.push_back(k);
        }
        cout << b.size() << "\n";
        for (int bi : b) cout << bi << " ";
        cout << "\n";
    }
}