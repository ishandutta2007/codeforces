#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcountll
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC
#define debug(x) std::cout << #x << ": " << x << '\n';
signed main() {
    int n;
    cin >> n;
    vector <vector <int> > a(n, vector <int> (n));
    for (int sum = 0; sum <= 2 * (n - 1); ++sum) {
        int t = 0;
        for (int x = 0; x <= sum; ++x) {
            int y = sum - x;
            if (0 <= x && x < n && 0 <= y && y < n) {
                a[x][y] = t * (1ll << sum);
            }
            t ^= 1;
        }   
    }   
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << a[i][j] << ' ';
        }   
        cout << endl;
    }   
    int q;
    cin >> q;
    while (q--) {
        int sum;
        cin >> sum;
        int x = 0, y = 0;
        cout << 1 << ' ' << 1 << endl;
        for (int t = 0; t < 2 * (n - 1); ++t) {
            bool w = (sum >> (t + 1)) & 1;
            if (x + 1 < n && w == !!a[x+1][y]) {
                x++;
            }      
            else {
                y++;
            }   
            cout << x + 1 << ' ' << y + 1 << endl;
        }   
    }   
}