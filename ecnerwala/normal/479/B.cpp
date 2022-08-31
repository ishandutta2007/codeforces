#include<bits/stdc++.h>
using namespace std;

int main() {
int n, k; cin >> n >> k;
int a[n];
for(int i = 0;  i< n; i++) cin >> a[i];
vector<pair<int, int>> res;
for(int i = 0; i < k; i++) {
int mi = 0, ma = 0;
for(int j = 0; j < n; j++) {
if(a[j] < a[mi]) mi = j;
if(a[j] > a[ma]) ma = j;
}
if(a[mi] + 1 >= a[ma]) break;
res.push_back(make_pair(ma + 1, mi + 1));
a[mi] ++, a[ma] --;
}
int mi = 0, ma = 0;
for(int j = 0; j < n; j++) {
if(a[j] < a[mi]) mi = j;
if(a[j] > a[ma]) ma = j;
}
cout << a[ma] - a[mi] << ' ' << res.size() << '\n';
for(auto i : res) cout << i.first << ' ' << i.second << '\n';
return 0;
}