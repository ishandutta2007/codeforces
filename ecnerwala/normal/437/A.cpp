#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int a[200], v[200];
bool g[200];

int main() {
int n = 4;
for(int i = 0; i < n; i++) { string s; cin >> s; a[i] = v[i]= s.size() - 2;
}
sort(v, v + 4);
if(v[0] * 2 <= v[1]) for(int i = 0; i < n; i++) if(a[i] == v[0]) g[i] = true;
if(v[3] >= 2 * v[2]) for(int i = 0; i < n; i++) if(a[i] == v[3]) g[i] = true;
if(g[0] + g[1] + g[2] + g[3] == 1) {for(int i = 0; i < n; i++) if(g[i]) cout << char('A' + i) << '\n';}
else cout << 'C' << '\n';
return 0;
}