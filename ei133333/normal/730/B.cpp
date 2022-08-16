#include <bits/stdc++.h>

using namespace std;

void Answer(int x, int y)
{
  cout << "! " << x + 1 << " " << y + 1 << endl;
}

bool Compare(int x, int y)
{
  cout << "? " << x + 1 << " " << y + 1 << endl;
  char c;
  cin >> c;
  return (c == '>');
}

int main()
{
  int T;
  cin >> T;
  while(T--) {
    int N;
    cin >> N;

    if(N == 1) {
      Answer(0, 0);
      continue;
    }

    vector< int > win, lose;
    for(int i = 0; i < N / 2; i++) {
      if(Compare(i * 2, i * 2 + 1) == 1) {
        win.push_back(i * 2);
        lose.push_back(i * 2 + 1);
      } else {
        win.push_back(i * 2 + 1);
        lose.push_back(i * 2);
      }
    }
    if(N & 1) {
      win.push_back(N - 1);
      lose.push_back(N - 1);
    }

    int ma = 0, mi = 0;
    for(int i = 1; i < win.size(); i++) {
      assert(win[i] != win[ma]);
      if(Compare(win[i], win[ma]) == 1)ma = i;
    }

    for(int i = 1; i < lose.size(); i++) {
      assert(lose[mi] != lose[i]);
      if(Compare(lose[mi], lose[i]) == 1)mi = i;
    }

    Answer(lose[mi], win[ma]);
  }
}