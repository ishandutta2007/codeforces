#include <bits/stdc++.h>

using namespace std;

int N, A, B;

int dfs(int latte, int malta, vector< int > &beet)
{
  if(latte == 0 && malta == 0) {
    return (0);
  }

  int ret = 114514;
  if(latte > 0) {
    beet.push_back(N - A);
    ret = min(ret, dfs(latte - 1, malta, beet) + 1);
    beet.pop_back();

    for(int i = 0; i < beet.size(); i++) {
      if(A <= beet[i]) {
        vector< int > renew;
        for(int j = 0; j < beet.size(); j++) {
          if(i == j) continue;
          renew.emplace_back(beet[j]);
        }
        renew.emplace_back(beet[i] - A);
        ret = min(ret, dfs(latte - 1, malta, renew));
      }
    }

  } else {

    beet.push_back(N - B);
    ret = min(ret, dfs(latte, malta - 1, beet) + 1);
    beet.pop_back();

    for(int i = 0; i < beet.size(); i++) {
      if(B <= beet[i]) {
        vector< int > renew;
        for(int j = 0; j < beet.size(); j++) {
          if(i == j) continue;
          renew.emplace_back(beet[j]);
        }
        renew.emplace_back(beet[i] - B);
        ret = min(ret, dfs(latte, malta - 1, renew));
      }
    }
  }

  return (ret);
}

int main()
{
  cin >> N >> A >> B;
  vector< int > beet;
  cout << dfs(4, 2, beet) << endl;
}