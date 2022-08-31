#include <bits/stdc++.h>

using namespace std;


string S;
int idx;
string Emin[256], Tmin[256], Fmin[256];

bool chmin(string &a, string b)
{
  if(a.empty() || a.size() > b.size() || (a.size() == b.size() && b < a)) {
    a = b;
    return (true);
  }
  return (false);
}

int main()
{
  fill_n(Emin, 256, string(1000, '~'));
  fill_n(Tmin, 256, string(1000, '~'));
  fill_n(Fmin, 256, string(1000, '~'));

  Fmin[0b00001111] = "x";
  Fmin[0b00110011] = "y";
  Fmin[0b01010101] = "z";
  bool update = true;
  while(update) {
    update = false;
    for(int i = 0; i < 256; i++) {
      update |= chmin(Fmin[i ^ 255], "!" + Fmin[i]);
      update |= chmin(Fmin[i], "(" + Emin[i] + ")");
      update |= chmin(Emin[i], Tmin[i]);
      update |= chmin(Tmin[i], Fmin[i]);
      for(int j = 0; j < 256; j++) {
        update |= chmin(Emin[i | j], Emin[i] + "|" + Tmin[j]);
        update |= chmin(Tmin[i & j], Tmin[i] + "&" + Fmin[j]);
      }
    }
  }

  int N;
  cin >> N;
  while(N--) {
    string bit;
    cin >> bit;
    int bits = 0;
    for(int i = 0; i < 8; i++) if(bit[i] == '1') bits |= 1 << (7 - i);
    cout << Emin[bits] << endl;
  }
}