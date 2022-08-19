#include<bits/stdc++.h>

using namespace std;

const int maxn = 2e6;
int n;
int a[maxn];
int p[maxn], s[maxn];
int bit[maxn];

void insert(int a) {
for(int i = a; i <= n; i += i & (-i)) bit[i] ++;
}

int query(int a){
int res = 0;
for(int i = a; i > 0; i -= i & (-i)) res += bit[i];
return res;
}

int main() {
ios_base::sync_with_stdio(0);
cin >> n;
for(int i = 0; i < n; i++) cin >> a[i];
map<int, int> mp;
for(int i = 0; i < n; i++) {
int v = a[i];
if(mp.count(v)) mp[v] ++;
else mp[v] = 1;
p[i] = mp[v];
}
mp.clear();
long long res = 0;
for(int i = n - 1; i >= 0; i--) {
int v = a[i];
if(mp.count(v)) mp[v] ++;
else mp[v] = 1;
s[i] = mp[v];
res += query(p[i] - 1);
insert(s[i]);
}
cout << res << '\n';
return 0;
}