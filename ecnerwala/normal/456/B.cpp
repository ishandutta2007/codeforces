#include<bits/stdc++.h>

using namespace std;

int main() {
string s; cin >> s;
int v = (s.back() - '0');
s.pop_back();
if(!s.empty()) v += 10 * (s.back() - '0');
v %= 4;
if(v == 0) cout << 4 << '\n';
else  cout << 0 << '\n';
}