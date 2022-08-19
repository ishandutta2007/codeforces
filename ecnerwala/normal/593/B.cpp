#include<bits/stdc++.h>
using namespace std;

int N;
typedef long long ll;
typedef pair<ll, ll> pll
;
ll X1, X2;
pll Y[2000000];

int main() {
cin >> N >> X1 >> X2;
for(int i = 0; i < N; i++) {
ll k, b; cin >> k >> b;
Y[i] = pll(k * X1 + b, k * X2 + b);
}
sort(Y, Y + N);
bool res = false;
for(int i = 1; i  < N; i++) {
if (Y[i].second < Y[i-1].second) res = true;
}
if(res) cout << "Yes\n"; else cout << "No\n";
}