#include<bits/stdc++.h>

using namespace std;

using int64 = long long;


int main() {
  int N;

  cin >> N;
  map <int, int > mp;
  for(int i = 0; i < N; i++) {
    int x;
    cin >> x;
    mp[x]++;
  }
  int ret = 0;
  for(auto& p : mp) ret = max(ret, p.second);
  cout << ret << endl;

}