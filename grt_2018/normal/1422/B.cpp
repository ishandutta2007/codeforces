#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using ll = long long;
using pi = pair<int,int>;

#define ST first
#define ND second
#define PB push_back

int t,n,m;
int a[110][110];



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> m;
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                cin >> a[i][j];
            }
        }
        ll ans = 0;
        for(int i = 1; 2 * i <= n + 1; ++i) {
            for(int j = 1; 2 * j <= m + 1; ++j) {
                vi v = {a[i][j], a[n - i + 1][j], a[i][m - j + 1], a[n - i + 1][m - j + 1]};
                if(i == n - i + 1 && j == m - j + 1) continue;
                if(i == n - i + 1) {
                    v = {a[i][j], a[i][m - j + 1]};
                    for(int x : v) {
                        //cout << i << " " << j << ": " << x << "\n";
                        ans += abs(x - ((v[0] + v[1])/2));
                    }
                } else if(j == m - j + 1) {
                    v = {a[i][j], a[n - i + 1][j]};
                    for(int x : v) {
                        //cout << i << " " << j << ": " << x << "\n";
                        ans += abs(x - ((v[0] + v[1])/2));
                    }
                } else {
                    sort(v.begin(), v.end());
                    for(int x : v) {
                        //cout << i << " " << j << ": " << x << "\n";
                        ans += abs(x - ((v[1] + v[2])/2));
                    }
                }
            }
        }
        cout << ans << "\n";
    }


}