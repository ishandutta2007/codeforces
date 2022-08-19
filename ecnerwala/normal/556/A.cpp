#include<bits/stdc++.h>
using namespace std;
int main() {
int n; string s; cin >> n >> s;
int res = 0;
for(char c : s) res += (c - '0' ? 1 : -1);
cout << abs(res) << '\n';
return 0;
}