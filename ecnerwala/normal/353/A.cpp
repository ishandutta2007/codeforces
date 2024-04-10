#include<iostream>

using namespace std;

int main() {
int n; cin >> n;
int s1 = 0, s2 = 0, diff = 0;
for(int i = 0; i < n; i++) {
int x, y; cin >> x >> y; x %= 2, y %= 2;
s1 += x;
s2 += y;
diff += (x != y);
}
s1 %= 2, s2 %= 2;
if(s1 != s2) cout << -1;
else if(s1 == 0) cout << 0;
else if(diff == 0) cout << -1;
else cout << 1;
cout << '\n';
return 0;
}