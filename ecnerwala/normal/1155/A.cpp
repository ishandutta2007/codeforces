#include<bits/stdc++.h>
using namespace std;

int main() {
int N; string S; cin >> N >> S;
for (int i = 0; i+1 < N; i++) {
if (S[i] > S[i+1]) {
cout << "YES" << '\n' << i+1 << ' ' << i+2 << '\n';
exit(0);
}
}
cout << "NO" << '\n';
return 0;
}