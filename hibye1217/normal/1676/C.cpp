#include <bits/stdc++.h>
using namespace std;
string arr[60];
int main(){ios_base::sync_with_stdio(0);cin.tie(0);
int t; cin >> t;
while (t--){
int n, m; cin >> n >> m;
for (int i = 1; i <= n; i++){ cin >> arr[i]; }
int mn = 1e9;
for (int i = 1; i <= n; i++){
for (int j = i+1; j <= n; j++){
int res = 0;
for (int k = 0; k < m; k++){
res += abs(arr[i][k] - arr[j][k]);
}
mn = min(mn, res);
}
}
cout << mn << '\n';
}
}