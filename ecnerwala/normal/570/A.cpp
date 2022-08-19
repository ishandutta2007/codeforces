#include<bits/stdc++.h>
using namespace std;

int cnt[200];
int n, m;
int main() {
cin >> n >> m;
for(int i = 0; i < m; i++) {
int win = -1, best = -1;
for(int j = 0; j < n; j++) {
int v; cin >> v; if(v > best) best = v, win = j;
}
cnt[win] ++;
}
int win = -1;
for(int j = 0; j < n; j++) if(cnt[j] > cnt[win]) win = j;
cout << win +1 << '\n';
return 0;
}