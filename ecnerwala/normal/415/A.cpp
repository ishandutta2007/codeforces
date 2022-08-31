#include<bits/stdc++.h>

using namespace std;

int n, m;
int b[200];
int main() {
cin >> n >> m;
for(int i = 0; i < m; i++) cin >> b[i];
for(int i = 1; i <= n; i++) {
for(int j = 0; j < m; j++) {
if(b[j] <= i) {
cout << b[j] << '\n';
break;
}
}
}
return 0;
}