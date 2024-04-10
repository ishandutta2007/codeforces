#include<iostream>

using namespace std;

bool isGood(int v, int k) {
int sum = 0;
for(;v; v /= 10) {if(v % 10 <= k) sum = sum | (1 << (v % 10));}
return sum + 1 == (1 << (k + 1));
}
int main() {
int n, k;
cin >> n >> k;
int ans  = 0;
for(int i = 0; i < n; i++ ){
int v; cin >> v;
if(isGood(v, k)) ans++;
}
cout << ans << '\n';
return 0;
}