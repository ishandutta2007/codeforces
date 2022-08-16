#include<bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  int N, M;

  cin >> N >> M;
  vector< int > sum[3000];
  for(int i = 0; i < N; i++) {
    int p, c;
    cin >> p >> c;
    --p;
    sum[p].push_back(c);
  }
  for(int i = 0; i < M; i++) {
    sort(begin(sum[i]), end(sum[i]));
    reverse(begin(sum[i]), end(sum[i]));
  }

  int64 ret = 1LL << 60;
  for(int i = 1; i <= 3000; i++) {
    int rest = i - (int) sum[0].size();
    int64 add = 0;
    vector< int > vs;
    for(int j = 1; j < M; j++) {
      for(int k = 0; k < i-1 && k < sum[j].size(); k++) {
        vs.push_back(sum[j][k]);
      }
      for(int k = i-1; k < sum[j].size(); k++) {
        add += sum[j][k];
        --rest;
      }
    }
    sort(begin(vs), end(vs));
    if(vs.size() < rest) {
      continue;
    }
    for(int j = 0; j < rest; j++) {
      add += vs[j];
    }
    ret = min(ret, add);
  }

  cout << ret << endl;
}