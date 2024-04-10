#include<bits/stdc++.h>
using namespace std;
int main() {
int N; string S; cin >> N >> S;
int r = 0, s = 0;
for (char c : S) {
r = max(r, s += (c == '-'?1:-1));
}
cout << r-s << '\n';
}