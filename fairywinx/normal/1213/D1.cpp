#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k, a;
    int ans = 1e9;
    cin >> n >> k;
    vector< vector<int> > b(1e5 * 2 + 1, vector<int> (0));
    for(int i = 0; i < n; ++i) {
        cin >> a;
        int j = 1;
        b[a].push_back(0);
        while(a > 0) {
            a /= 2;
            b[a].push_back(j);
            ++j;
        }
    }
    for(int i = 0; i < (1e5 * 2 + 1); ++i) {
        sort(b[i].begin(), b[i].end());
        a = 0;
        if (b[i].size() >= k) {
            for(int j = 0; j < k; ++j) {
                a += b[i][j];
            }
            ans = min(a, ans);
        }
    }
    /*for(int i = 0; i < 10; ++i) {
        for(int j = 0; j < b[i].size(); ++j) {
            cout << b[i][j] << ' ';
        }
        cout << i << endl;
    }*/
    cout << ans;
}