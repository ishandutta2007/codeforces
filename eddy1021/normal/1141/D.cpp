#include <bits/stdc++.h>
using namespace std;
constexpr int N = 202020;
constexpr int q = int('?');
int n;
char c[N];
vector<int> id[2][256];
vector<pair<int, int>> ans;
void match(int a, int b) {
  while (id[0][a].size() and id[1][b].size()) {
    ans.push_back({id[0][a].back(),
                   id[1][b].back()});
    id[0][a].pop_back();
    id[1][b].pop_back();
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < 2; ++i) {
    scanf("%s", c);
    for (int j = 0; j < n; ++j) {
      id[i][int(c[j])].push_back(j + 1);
    }
  }
  for (int i = 'a'; i <= 'z'; ++i) {
    match(i, i);
  }
  for (int i = 'a'; i <= 'z'; ++i) {
    match(q, i);
    match(i, q);
  }
  match(q, q);
  printf("%d\n", (int)ans.size());
  for (auto p: ans) {
    printf("%d %d\n", p.first, p.second);
  }
}