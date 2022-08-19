#include<bits/stdc++.h>
using namespace std;

int main() {
int n, d; cin >> n >> d;
int res = 0;
int cnt = 0;
for(int i = 0; i < d; i++) {
string s; cin >> s;
bool good = true;
for(char c : s) if(c == '0') good = false;
if(good) cnt = 0;
else res = max(res, ++cnt);
}
cout << res << '\n';
return 0;
}