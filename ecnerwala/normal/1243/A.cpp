#include<bits/stdc++.h>
using namespace std;
int main() {
int K; cin >> K;
while (K--) {
 int n; cin >> n; vector<int> a(n);
 for (int i = 0; i < n; i++) cin >> a[i];
 sort(a.begin(), a.end()); reverse(a.begin(), a.end());
 int ans = 0;
 for (int i = 0; i < n; i++) { ans = max(ans, min(a[i], i+1)); }
 cout << ans << '\n';
}
}