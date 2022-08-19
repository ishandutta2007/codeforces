#include<iostream>

using namespace std;

int main() {
int n, m; cin >> n >> m;
int cur = 0, res = 0;
for(int i = 0; i < n; i++) {
int a; cin >> a;
cur += a;
if(cur > m) cur = a, res++;
}
if(cur) res++;
cout << res << '\n';
return 0;
}