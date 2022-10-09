#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int q;
    cin >> q;
    for(int u = 0; u < q; ++u) {
        int h, n, ans = 0;
        cin >> h >> n;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        reverse(a.begin(), a.end());
        while(a.size() > 2) {
            int i = a.size() - 1;
            a[i] = a[i - 1] + 1;
            if (a[i] > a[i - 2] + 2) {
                ans++;
                a.pop_back();
                a.pop_back();
                a.push_back(a[i - 2] + 1);
            }
            else {
                a.pop_back();
                a.pop_back();
            }

            //for(int j = a.size() - 1; j >= 0; --j) cout << a[j] << ' ' ;
            //cout << endl;
        }
        if (a.size() == 2) if (a[0] > 1) ans++;
        cout << ans << endl;
    }
}