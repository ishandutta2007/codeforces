#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i=0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end(), greater<int>());
    int m;
    int sum = 0;
    for (int i=0; i < n; i++) sum += v[i];
    cin >> m;
    for (int i=0; i < m; i++){
        int kek;
        cin >> kek;
        cout << sum - v[kek-1] << "\n";
    }
}