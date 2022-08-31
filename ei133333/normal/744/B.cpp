#include <bits/stdc++.h>

using namespace std;

const int INF = 1 << 30;

vector< int > ck[1000];

void ei(int a, int b, int c, int d, int dep = 0)
{
  if(dep == 22) return;

  int m1 = (a + c) / 2;
  int m2 = (b + d) / 2;
  for(int i = a; i < m1; i++) ck[dep].push_back(i);
  for(int i = m1; i < c; i++) ck[dep + 1].push_back(i);

  ei(a, b, m1, m2, dep + 2);
  ei(m1, m2, c, d, dep + 2);
}

int main()
{
  int N;
  cin >> N;
  ei(0, 0, N, N);
  vector< int > cc, vv(N, INF);
  for(int i = 0; i < 20; i++) {
    if(ck[i].empty()) break;
    cout << ck[i].size() << endl;
    bool kill[1000] = {};
    for(int &s : ck[i]) {
      kill[s]++;
      cout << s + 1 << " ";
    }
    cout << endl;
    fflush(stdout);

    for(int j = 0; j < N; j++) {
      int mins;
      cin >> mins;
      if(kill[j]) continue;
      vv[j] = min(vv[j], mins);
    }
  }

  cout << -1 << endl;
  for(int i = 0; i < N; i++) {
    cout << vv[i] << " ";
  }
  cout << endl;
  fflush(stdout);
}