#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int mod = 998244353;

int n, m;
int arr[1000005];
vector<int> who[505];

int mem[505][505];

vector<int> allL, allR;

int invertL[505];
int invertR[505];

int solve(int l, int r, int dep) {
  if (l < 0 || r < 0 || l >= n || r >= n || allL[l] >= allR[r]) return 1;
  if (mem[l][r] != -1) return mem[l][r];
  
  int indexL = l;
  for (int i = l; i < n; ++i) {
    if (allL[i] > allR[r]) break;
    if (arr[allL[indexL]] > arr[allL[i]])
      indexL = i;
  }
  int indexR = invertR[arr[allL[indexL]]];
  
  int ret1 = 0;
  for (int a = indexL; a >= l; ) {
    int ind1 = (allL[a] - 1 <= allL[l]) ? -1 : invertR[arr[allL[a] - 1]];
    int ind2 = (allL[indexL] - 1 <= allL[l]) ? -1 : invertR[arr[allL[indexL] - 1]];
    ret1 = (ret1 + 1LL * solve(l, ind1, dep + 1) * solve(a, ind2, dep + 1) % mod) % mod;
  
    a = (allL[a] - 1 < allL[l]) ? -1 : invertL[arr[allL[a] - 1]];
  }

  int ret2 = 0;
  for (int b = indexR; b <= r; ) {
    int ind1 = (allR[indexR] + 1 < allR[r]) ? invertL[arr[allR[indexR] + 1]] : -1;
    int ind2 = (allR[b] + 1 < allR[r]) ? invertL[arr[allR[b] + 1]] : -1;
    ret2 = (ret2 + 1LL * solve(ind1, b, dep + 1) * solve(ind2, r, dep + 1) % mod) % mod;

    b = (allR[b] + 1 <= allR[r]) ? invertR[arr[allR[b] + 1]] : r + 1;
  }

  int num = arr[allL[indexL]];

  int ret3 = 1;
  for (int i = 1; i < who[num].size(); ++i) {
    if (who[num][i - 1] + 1 < who[num][i]) {
      int ind1 = (who[num][i - 1] + 1) < allR[indexR] ? invertL[arr[who[num][i - 1] + 1]] : -1;
      int ind2 = (who[num][i] - 1) >= allL[indexL] ? invertR[arr[who[num][i] - 1]] : -1;
      ret3 = 1LL * ret3 * solve(ind1, ind2, dep + 1) % mod;
    }
  }

  // cout << "Ans: " << allL[l] << " " << allR[r] << " " << ret1 * ret2 * ret3 << endl;
  return mem[l][r] = 1LL * ret1 * ret2 % mod * ret3 % mod;
}

int main() {
  cin >> n >> m;

  int mn[505] = {0}, mx[505] = {0};
  memset(mn, -1, sizeof(mn));
  memset(mx, -1, sizeof(mx));
  for (int i = 0; i < m; ++i) {
    cin >> arr[i];
    if (mn[arr[i]] == -1) mn[arr[i]] = i;
    mx[arr[i]] = i;
    who[arr[i]].push_back(i);
  }

  bool isBad = false;
  for (int i = 1; i <= n; ++i) {
    allL.push_back(mn[i]);
    allR.push_back(mx[i]);
  }
  vector<int> st;
  for (int i = 0; i < m; ++i) {
    if (st.size() > 0 && st.back() > arr[i]) {
      cout << 0 << endl;
      return 0;
    }
    st.push_back(arr[i]);
    while (st.size() > 0 && st.back() == arr[i] && i == mx[arr[i]]) st.pop_back();
  }

  sort(allL.begin(), allL.end());
  sort(allR.begin(), allR.end());

  for (int i = 0; i < allL.size(); ++i) {
    invertL[arr[allL[i]]] = i;
  }
  for (int i = 0; i < allR.size(); ++i) {
    invertR[arr[allR[i]]] = i;
  }

  memset(mem, -1, sizeof(mem));
  cout << solve(0, n - 1, 0) << endl;
  return 0;
}