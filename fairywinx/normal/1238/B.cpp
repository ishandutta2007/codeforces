#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int q;
    cin >> q;
    for(int u = 0; u < q; ++u) {
        int n, r, x;
        cin >> n >> r;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        for(int i = 1; i <= n; ++i) {
            x = a[a.size() - 1];
            a.pop_back();
            //cout << x << ' ';
            while(a.size() > 0 && a[a.size() - 1] == x) a.pop_back();
            if (a.size() == 0 || (a[a.size() - 1] + (r - 1)) / r - i <= 0) {
                cout << i << endl;
                break;
            }
        }
    }
}