#include<bits/stdc++.h>
using namespace std;
int main() {
string s; cin >> s;
vector<int> v = {0,0};
for (int i = 1; i < int(s.size()); i++) v.push_back(s[i]==s[i-1]);
for (int i = 1; i < int(v.size()); i++) v[i] += v[i-1];
int q; cin >> q;
for (int i = 0; i < q; i++) {
int l,r; cin >> l >> r;
cout << v[r]-v[l] << '\n';
}
}