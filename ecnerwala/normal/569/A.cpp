#include<bits/stdc++.h>
using namespace std;

int main() {
int t, s, q; cin >> t >> s >> q;
int res = 0;
while(t >s) s *= q, res++;
cout << res << '\n';
return 0;
}