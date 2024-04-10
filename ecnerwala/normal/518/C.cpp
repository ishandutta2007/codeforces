#include<bits/stdc++.h>

using namespace std;

int n, m, k;
int a[1000000],b[1000000];

int main() {
cin >> n >> m >> k;
for(int i=0;i < n; i++) {
cin >> a[i]; a[i] --;
b[a[i]] = i;
}
long long r = m;
for(int q = 0; q< m ; q++) {
int v; cin >> v; v--;
int i = b[v];
r += i / k;
if(i) {
swap(a[i], a[i-1]);
b[a[i]] = i;
b[a[i-1]]=i-1;
}
}
cout << r << '\n';
return 0;
}