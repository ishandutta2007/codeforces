#include <bits/stdc++.h>
using namespace std;

#define int long long

const int ms = 5e5+5;
const int mod = 1e9+7;

int n;
map<int, int> dic;
map<int, int> dicInv;
int bit1[ms], bit2[ms];
int arr[ms];

void update(int idx, int v1, int v2) {
  while(idx <= n) {
    bit1[idx] = (bit1[idx] + v1) % mod;
    bit2[idx] = (bit2[idx] + v2) % mod;
    idx += idx & -idx;
  }
}

pair<int, int> query(int idx) {
  pair<int, int> ans;
  while(idx > 0) {
    ans.first = (ans.first + bit1[idx]) % mod;
    ans.second = (ans.second + bit2[idx]) % mod;
    idx -= idx & -idx;
  }
  return ans;
}

main() {
  cin.tie(0); ios::sync_with_stdio(0);
  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> arr[i];
    dic[arr[i]] = 0;
    dicInv[-arr[i]] = 0;
  }
  int cur = 0;
  for(auto &p : dic) p.second = ++cur;
  cur = 0;
  for(auto &p : dicInv) p.second = ++cur;
  int ans = 0;
  int sum = 0;
  for(int i = 1; i <= n; i++) {
    int pos = dic[arr[i]];
    int posInv = dicInv[-arr[i]];
    int valSum = query(posInv).second;
    int valI = query(pos).first;
    sum = (sum + valSum + valI * arr[i] % mod + arr[i] * i % mod) % mod;
    //cout << valSum << ' ' << valI << ' ' << sum << endl;
    update(pos, i, 0);
    update(posInv, 0, arr[i]*i % mod);
    ans = (ans + sum) % mod;
  }
  cout << ans << endl;
}