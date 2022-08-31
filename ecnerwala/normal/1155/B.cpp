#include<bits/stdc++.h>
using namespace std;

int main() {
int N; string S; cin >> N >> S;
N -= 10;
S = S.substr(0, N);
int c8 = 0;
for (char c : S) c8 += (c == '8');
cout << ((c8 > N / 2) ? "YES" : "NO") << '\n';
}