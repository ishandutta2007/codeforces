#include<bits/stdc++.h>

using namespace std;

int main() {
int N;cin >> N;
string s; cin >> s;
int res = 1;
for(int i = 0; i < N; i++) {
if(s[i] == '1') res++;
else break;
}
if(res > N)  res = N;
cout << res << '\n';
return 0;
}