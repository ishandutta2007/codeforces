#include<bits/stdc++.h>
using namespace std;
char c[500000];
int n, m;
int main() {
cin >> n >> m >> (c + 1);
int v = 0;
for(int i = 0; i <= n; i++) {
v += (c[i] == '.' && c[i + 1] == '.');
}
while(m--){
int i; cin >> i;
v -= (c[i] == '.' && c[i - 1] == '.') + (c[i] == '.' && c[i + 1] == '.');
cin >> c[i];
v += (c[i] == '.' && c[i - 1] == '.') + (c[i] == '.' && c[i + 1] == '.');
cout << v << '\n';
}
}