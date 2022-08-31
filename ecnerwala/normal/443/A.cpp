#include<bits/stdc++.h>

using namespace std;

bool seen[100];

int main() {
string s; getline(cin, s);
int res = 0;
for(int i = 1; i < int(s.size()); i += 3) {
int v = s[i] - 'a';
if(v < 0 || v >= 26) break;
if(!seen[v]) res++, seen[v] = true;
}
cout << res << '\n';
return 0;
}