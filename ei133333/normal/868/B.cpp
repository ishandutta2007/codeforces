#include <bits/stdc++.h>

using namespace std;

int main()
{
  double H, M, S, T1, T2;

  cin >> H >> M >> S >> T1 >> T2;


  T1 *= 30;
  T2 *= 30;
  T1 += 360 * 2;
  T2 += 360 * 2;
  
  vector< double > cut;
  for(int i = 0; i <= 360 * 5; i += 360) {
    cut.push_back((H * 3600 + M * 60 + S) * 360 / 12 / 60 / 60 + i);
    cut.push_back((M * 60 + S) * 360 / 60 / 60 + i);
    cut.push_back(S * 6 + i);
  }
  
  sort(begin(cut), end(cut));
  for(int i = 1; i < cut.size(); i++) {
    if(cut[i - 1] <= T1 && T1 <= cut[i] && cut[i - 1] <= T2 && T2 <= cut[i]) {
      cout << "YES" << endl;
      return (0);
    }
    if(cut[i - 1] <= T1 - 360 && T1 - 360 <= cut[i] && cut[i - 1] <= T2 && T2 <= cut[i]) {
      cout << "YES" << endl;
      return (0);
    }

    if(cut[i - 1] <= T1 + 360 && T1 + 360 <= cut[i] && cut[i - 1] <= T2 && T2 <= cut[i]) {
      cout << "YES" << endl;
      return (0);
    }
  }

  cout << "NO" << endl;
}