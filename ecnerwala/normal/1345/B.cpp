#include<bits/stdc++.h>
int main(){
using namespace std; ios_base::sync_with_stdio(false); cin.tie(nullptr);
int T; cin >> T;
while (T--) {
int N; cin >> N; int ans = 0;
while (N >= 2) { ans ++; for (int i = 1; 3*i-1 <= N; i++) N -= 3*i-1; }
cout << ans << '\n';
}
}