#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int n;
int arr[100005], ans[100005];

int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  vector<pair<int, int>> v;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
    v.push_back({arr[i], i});
  }
  sort(v.rbegin(), v.rend());
  for (int i = 0; i < v.size(); ++i) {
    bool has2 = false;
    for (int j = v[i].second; j < n; j += v[i].first) {
      if (ans[j] == 2 && arr[j] > v[i].first) {
        has2 = true;
        break;
      }
    }
    for (int j = v[i].second; j >= 0; j -= v[i].first) {
      if (ans[j] == 2 && arr[j] > v[i].first) {
        has2 = true;
        break;
      }
    }
    ans[v[i].second] = has2 ? 1 : 2;
  }
  for (int i = 0; i < n; ++i)
    cout << (char) ('A' + ans[i] - 1);
  cout << endl;
  return 0;
}