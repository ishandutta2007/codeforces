#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long

int main(){
ll n, a[3005], ans = 0;
cin >> n;
for (int i = 0; i < n; i++) cin >> a[i];
sort(a, a + n);
for (int i = 1; i < n; i++){
if (a[i] == a[i - 1]){
int j = i;
while (a[j] == a[i - 1]){
a[j]++;
j++;
ans++;
}
}
}
cout << ans << '\n';
}