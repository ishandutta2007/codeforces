#include<bits/stdc++.h>

using namespace std;

int A[4];
int main() {
for(int i = 0; i < 4; i++) cin >> A[i];
string s; cin >> s;
int res = 0;
for(char c : s) res += A[c - '1'];
cout << res << '\n';
return 0;
}