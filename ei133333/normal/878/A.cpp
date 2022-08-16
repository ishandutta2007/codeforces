#include<bits/stdc++.h>

using namespace std;


int main()
{
  int N;
  scanf("%d", &N);

  bool v[10][2];
  for(int i = 0; i < 10; i++) {
    v[i][0] = false;
    v[i][1] = true;
  }

  for(int i = 0; i < N; i++) {
    char c;
    int s;
    scanf(" %c %d", &c, &s);
    for(int j = 0; j < 10; j++) {
      bool f = (s >> j) & 1;
      for(int k = 0; k < 2; k++) {
        if(c == '|') v[j][k] |= f;
        else if(c == '&') v[j][k] &= f;
        else v[j][k] ^= f;
      }
    }
  }

  int t[3] = {};
  t[2] = (1 << 10) - 1;

  for(int i = 0; i < 10; i++) {
    int bit = 1 << i;
    if(!v[i][0]) {
      if(!v[i][1]) t[2] &= ~bit;
    } else {
      if(!v[i][1]) t[1] |= bit;
      else t[0] |= bit;
    }
  }

  cout << 3 << endl;
  cout << "| " << t[0] << endl;
  cout << "^ " << t[1] << endl;
  cout << "& " << t[2] << endl;

}