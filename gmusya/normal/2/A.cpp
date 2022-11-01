#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector <pair <string, int>> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i].first >> arr[i].second;
  map <string, int> score;
  for (int i = 0; i < n; i++)
    score[arr[i].first] += arr[i].second;
  int ma = -1e9;
  set <string> se;
  for (auto &now : score)
    ma = max(now.second, ma);
  for (auto &now : score)
    if (now.second == ma)
      se.insert(now.first);
  score = map <string, int>();
  for (int i = 0; i < n; i++) {
    score[arr[i].first] += arr[i].second;
    if (score[arr[i].first] >= ma && se.find(arr[i].first) != se.end()) {
      cout << arr[i].first;
      return 0;
    }
  }
  return 0;
}