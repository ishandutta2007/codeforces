#include <bits/stdc++.h>

using namespace std;


int main()
{

  int A, B;
  cin >> A >> B;

  vector< pair< int, int > > latte, malta;
  for(int i = -1000; i <= 1000; i++) {
    for(int j = -1000; j <= 1000; j++) {
      if(i * i + j * j == A * A) latte.emplace_back(i, j);
      if(i * i + j * j == B * B) malta.emplace_back(i, j);
    }
  }

  for(auto& p : latte) {
    for(auto& q : malta) {
      if(p == q) continue;
      if(p.first == 0 || q.first == 0 || p.second == 0 || q.second == 0) continue;
      if(p.first == q.first) continue;
      if(p.second == q.second) continue;
      int far = (p.first - q.first) * (p.first - q.first) + (p.second - q.second) * (p.second - q.second);
      if(far == A * A + B * B) {
        cout << "YES" << endl;
        cout << 0 << " " << 0 << endl;
        cout << p.first << " " << p.second << endl;
        cout << q.first << " " << q.second << endl;
        return(0);
      }
    }
  }

  cout << "NO" << endl;
}