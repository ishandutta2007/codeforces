#include<bits/stdc++.h>
using namespace std;
const int vx[] = {0, 1, 0, -1}, vy[] = {1, 0, -1, 0};

const string temp = "URDL";

int main()
{
  int N;
  cin >> N;
  string S;
  cin >> S;
 
  int ret = 0;
  for(int i = 0; i < N; i++) {
    int x = 0, y = 0;
    for(int j = i; j < N; j++) {
      x += vx[temp.find(S[j])];
      y += vy[temp.find(S[j])];
      if(x == 0 && y == 0) ++ret;
    }
  }
  cout << ret << endl;
}