#include<bits/stdc++.h>
using namespace std;

int main() {
ios_base::sync_with_stdio(0);
int N; cin >> N;
int last = 1 << 30;
for (int i = 0; i < N; i++) {
int a, b; cin >> a >> b;
if (min(a,b) > last) {
cout << "NO\n"; return 0;
}
last = (max(a,b) <= last) ? max(a,b) : min(a,b);
}
cout << "YES\n";
}