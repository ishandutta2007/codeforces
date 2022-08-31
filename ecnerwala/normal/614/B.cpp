#include<bits/stdc++.h>
using namespace std;

int main() {
string out = "1";
int cnt = 0;
int n; cin >> n;
for(int i = 0; i < n; i++) {
string v; cin >> v;
if(v == "0") {
cout << "0\n";
return 0;
}
bool good = v[0] == '1';
for(int i = 1; i < int(v.size()); i++) good = good && (v[i] == '0');
if(good) cnt += int(v.size()) - 1;
else out = v;
}
cout << out;
for(int i = 0; i < cnt; i++) cout << '0';
cout << '\n';
}