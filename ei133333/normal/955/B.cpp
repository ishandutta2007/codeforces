#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  string S;
  cin >> S;
  vector< int > sum(256);
  for(auto &c : S) sum[c]++;

  for(char i = 'a'; i <= 'z'; i++) {
    for(char j = i + 1; j <= 'z'; j++) {
      for(int k = j + 1; k <= 'z'; k++) {
        for(char l = k + 1; l <= 'z'; l++) {
          bool f = true;
          for(int a = 'a'; a <= 'z'; a++) {
            if(i == a || j == a || k == a || l == a) continue;
            if(sum[a] > 0) f = false;
          }
          if(sum[i] == 0) f = false;
          if(sum[j] == 0) f = false;
          if(sum[k] == 0) f = false;
          if(sum[l] == 0) f = false;

          if(f) {
            cout << "Yes" << endl;
            return (0);
          }
        }
      }
    }
  }


  for(char i = 'a'; i <= 'z'; i++) {
    for(char j = 'a'; j <= 'z'; j++) {
      for(int k = 'a'; k <= 'z'; k++) {
        if(i == j || i == k || j == k) continue;

        bool f = true;
        for(int a = 'a'; a <= 'z'; a++) {
          if(i == a || j == a || k == a) continue;
          if(sum[a] > 0) f = false;
        }

        if(sum[i] <= 1) f = false;
        if(sum[j] == 0) f = false;
        if(sum[k] == 0) f = false;

        if(f) {
          cout << "Yes" << endl;
          return (0);
        }

      }
    }
  }

  for(char i = 'a'; i <= 'z'; i++) {
    for(int j = i + 1; j <= 'z'; j++) {

      bool f = true;
      for(int a = 'a'; a <= 'z'; a++) {
        if(i == a || j == a) continue;
        if(sum[a] > 0) f = false;
      }

      if(sum[i] <= 1) f = false;
      if(sum[j] <= 1) f = false;


      if(f) {
        cout << "Yes" << endl;
        return (0);
      }
    }
  }

  cout << "No" << endl;
}