#include<bits/stdc++.h>

using namespace std;

int main() {
int a, m; cin >> a >> m;
while(m % 2 == 0) m /= 2;
if(a % m == 0) cout << "Yes\n";
else cout << "No\n";
return 0;
}