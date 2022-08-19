#include<bits/stdc++.h>
using namespace std;

int main() {
int n; vector<int> x;
cin >> n;
for(int i = 0; i < n; i++) { int v; cin >> v; x.push_back(v); }
for(int i = 0; i < n; i++) { 
int mi, ma = max(x[i] - x[0], x[n - 1] - x[i]);
if(i == 0) mi = x[1] - x[0]; 
else if(i + 1 == n) mi = x[i] - x[i - 1];
else mi = min(x[i + 1] - x[i], x[i] - x[i - 1]);
cout << mi << ' ' << ma << '\n';
}
return 0;
}