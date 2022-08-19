#include<bits/stdc++.h>
using namespace std;
int main() {
int N; cin >> N;
map<pair<int, int>, vector<int>> mp;
map<int, int> cnt;
for (int i = 0; i < N-2; i++) {
int a, b, c; cin >> a >> b >> c;
cnt[a]++, cnt[b]++, cnt[c]++;
mp[{a,b}].push_back(c);
mp[{b,a}].push_back(c);
mp[{a,c}].push_back(b);
mp[{c,a}].push_back(b);
mp[{b,c}].push_back(a);
mp[{c,b}].push_back(a);
}
for (int i = 1; i <= N; i++) {
if (cnt[i] != 1) continue;
for (int j = 1; j <= N; j++) {
if (cnt[j] > 2 || !mp.count({i,j})) continue;
vector<int> res;
int k = mp[{i,j}][0];
cout << i << ' ' << j << ' ' << k;
for (int z = 3; z < N; z++) {
i = mp[{j,k}][0] ^ mp[{j,k}][1] ^ i;
cout << ' ' << i;
swap(i,j);
swap(j,k);
}
cout << '\n';
exit(0);
}
}
}