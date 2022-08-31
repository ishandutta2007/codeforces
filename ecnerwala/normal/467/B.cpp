#include<bits/stdc++.h>
using namespace std;

int cnt(int a) {
return a ? cnt(a & (a - 1)) + 1 : 0;
}
int cnt(int a, int b) { return cnt(a ^ b); }

int main() {
int n, m, k;
cin >> n >> m >> k;
vector<int> a;
for(int i = 0; i < m; i++) {
int v; cin >> v; a.push_back(v);
}
int r; cin >> r;
int res = 0;
for(int i = 0; i < m; i++) {
if(cnt(r, a[i]) <= k) res++;
}
cout << res << '\n';
return 0;
}