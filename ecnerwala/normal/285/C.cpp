#include<iostream>
#include<algorithm>

using namespace std;

int main() {
int n; cin >> n;
long long a[300005];
for(int i = 0; i < n; i++) cin >> a[i];
sort(a, a + n);
long long out = 0;
for(int i = 0; i < n; i++) {
out += abs(a[i] - i - 1);
}
cout << out << '\n';
return 0;
}