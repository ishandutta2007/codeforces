#include <bits/stdc++.h>
using namespace std;
 
#define inf 1000000000
#define inf_ll 1000000000000000000ll
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define pb push_back
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--) {
        int n, m, a, b; cin >> n >> m >> a >> b;
        if (n*a != m*b) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++)
                    cout << ((j-i*a+m*100)%m < a ? '1' : '0');
                cout << "\n";
            }
        }
    }
}