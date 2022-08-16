#include<bits/stdc++.h>

using namespace std;

using int64 = long long;

int main()
{
  int N;

  scanf("%d", &N);
  priority_queue< int, vector< int >, greater<> > que;
  int64 ret = 0;
  for(int i = 0; i < N; i++) {
    int p;
    scanf("%d", &p);
    if(!que.empty() && que.top() < p) {
      auto q = que.top();
      que.pop();
      ret += p - q;
      que.emplace(p);
      que.emplace(p);
    } else {
      que.emplace(p);
    }
  }
  cout << ret << endl;
}