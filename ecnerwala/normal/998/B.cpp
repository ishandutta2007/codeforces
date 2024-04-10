#include<bits/stdc++.h>
using namespace std;
int main() {
int N;
int B;
cin >> N >> B;
int s = 0;
int prv = -1;
vector<int> vals;
for (int i = 0; i < N; i++) {
int a; cin >> a;
if (i && s == 0) {
vals.push_back(abs(a-prv));
}
prv = a;
s += 2 * (a & 1) - 1;
}
sort(vals.begin(), vals.end());
reverse(vals.begin(), vals.end());
int res = 0;
while (!vals.empty() && B >= vals.back()) {
B -= vals.back();
vals.pop_back();
res ++;
}
cout << res << '\n';
}