#include <bits/stdc++.h>

using namespace std;

string S[10];

bool check()
{
  int a = 0, b = 0;
  for(int i = 0; i < 10; i++) {
    int sum = 0;
    for(int j = 0; j < 10; j++) {
      if(j == 0 || S[i][j - 1] == S[i][j]) {
        ++sum;
      } else {
        sum = 1;
      }
      if(S[i][j] == 'X') b = max(b, sum);
    }
  }
  for(int j = 0; j < 10; j++) {
    int sum = 0;
    for(int i = 0; i < 10; i++) {
      if(i == 0 || S[i - 1][j] == S[i][j]) {
        ++sum;
      } else {
        sum = 1;
      }
      if(S[i][j] == 'X') b = max(b, sum);
    }
  }
  for(int i = 0; i < 10; i++) {
    int sum = 0;
    for(int j = 0; j < 10 && i + j < 10; j++) {
      if(j == 0 || S[j - 1][i + j - 1] == S[j][i + j]) {
        ++sum;
      } else {
        sum = 1;
      }
      if(S[j][i + j] == 'X') b = max(b, sum);
    }
  }
  for(int i = 0; i < 10; i++) {
    int sum = 0;
    for(int j = 0; j < 10 && i - j >= 0; j++) {
      if(j == 0 || S[j - 1][i - j + 1] == S[j][i - j]) {
        ++sum;
      } else {
        sum = 1;
      }
      if(S[j][i - j] == 'X') b = max(b, sum);
    }
  }
  for(int i = 1; i < 10; i++) {
    int sum = 0;
    for(int j = 0; i + j < 10 && j < 10; j++) {
      if(j == 0 || S[i + j - 1][j - 1] == S[i + j][j]) {
        ++sum;
      } else {
        sum = 1;
      }
      if(S[i + j][j] == 'X') b = max(b, sum);
    }
  }
  for(int i = 1; i < 10; i++) {
    int sum = 0;
    for(int j = 0; i + j < 10 && j < 10; j++) {
      if(j == 0 || S[i + j - 1][10 - j] == S[i + j][10 - j - 1]) {
        ++sum;
      } else {
        sum = 1;
      }
      if(S[i + j][10 - j - 1] == 'X') b = max(b, sum);
    }
  }
  return(b >= 5);
}

int main()
{
  for(int i = 0; i < 10; i++) {
    cin >> S[i];
  }
  for(int i = 0; i < 10; i++) {
    for(int j = 0; j < 10; j++) {
      if(S[i][j] == '.') {
        S[i][j] = 'X';
        if(check()) {
          cout << "YES" << endl;
          return (0);
        }
        S[i][j] = '.';
      }
    }
  }
  cout << "NO" << endl;
}