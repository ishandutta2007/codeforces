#include <bits/stdc++.h>

using namespace std;

void Fail()
{
  cout << "NO" << endl;
  exit(0);
}

int main()
{
  int N;
  cin >> N;

  int nowHeight = 0;

  for(int i = 0; i < N; i++) {
    int d;
    string dir;
    cin >> d >> dir;
    if(dir == "South") {
      nowHeight += d;
      if(nowHeight > 20000) Fail();
    } else if(dir == "North") {
      nowHeight -= d;
      if(nowHeight < 0) Fail();
    } else if(nowHeight == 0 || nowHeight == 20000) Fail();
  }
  if(nowHeight != 0) Fail();
  cout << "YES" << endl;
}