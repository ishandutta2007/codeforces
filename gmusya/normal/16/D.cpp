#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector <int> time;
  string s;
  getline(cin, s);
  for (int i = 0; i < n; i++) {
    getline(cin, s);
    int t = ((s[1] - '0') * 600 + (s[2] - '0') * 60 + (s[4] - '0') * 10 + (s[5] - '0')) % 720;
    if (s[7] == 'p')
      t += 720;
    time.push_back(t);
  }
  int d = 1;
  int cnt = 0;
  for (int i = 1; i < n; i++) {
    if (time[i] < time[i - 1]) 
      d++;
    if (time[i] != time[i - 1]) {
      d += (cnt - 1) / 10;
      cnt = 0;
    }
    cnt++;
  }
  cout << d + (cnt - 1) / 10;
  return 0;
}