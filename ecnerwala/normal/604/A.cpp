#include<bits/stdc++.h>
using namespace std;

int m[5];
int w[5];
int hs, hu;

int main() {
int res = 0;
for(int i = 1; i <= 5; i++) cin >> m[i];
for(int i = 1; i <= 5; i++) cin >> w[i];
cin >> hs >> hu;
for(int i = 1; i <= 5; i++) res += max(500 * i * 3 / 10, (500 - 2 * m[i]) * i - 50 * w[i]);
res += 100 * hs;
res -= 50 * hu;
cout << res << '\n';
return 0;
}