#include<bits/stdc++.h>

using namespace std;

bool flip[2000000];

int main() {
string s; cin >> s;
int m; cin >> m;
vector<int> a;
for(int i = 0; i < m; i++) {
int v; cin >> v; v--; flip[v] = !flip[v];
}
for(int i = 1; i < 2000000; i++) {
if(flip[i - 1]) flip[i] = ! flip[i];
}
for(int i = 0; i < s.size() - i - 1; i++) {
if(flip[i]) swap(s[i], s[s.size() - i - 1]);
}
cout << s << '\n';
return 0;
}