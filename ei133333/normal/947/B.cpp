#include<bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  int N, V[100000];

  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> V[i];
  }
  priority_queue< int64, vector< int64 >, greater< int64 > > que;
  int64 base = 0;

  for(int i = 0; i < N; i++) {
    int x;
    cin >> x;
    que.emplace(V[i] + base);

    int64 cost = 1LL * x * que.size();
    base += x;
    while(que.size() && que.top() <= base) {
      cost -= base - que.top();
      que.pop();
    }
    cout << cost << " ";
  }
  cout << endl;

}