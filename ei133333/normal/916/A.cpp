#include<bits/stdc++.h>

using namespace std;

int main()
{
  int x, hh, mm;

  cin >> x;
  cin >> hh >> mm;

  int curr = hh * 60 + mm;
  for(int i = 0; ; i++) {
    int H = curr / 60, W = curr % 60;
    string s = to_string(H) + to_string(W);
    if(s.find('7') != string::npos) {
      cout << i << endl;
      return (0);
    }
    curr = (curr - x + 1440) % 1440;
  }
}