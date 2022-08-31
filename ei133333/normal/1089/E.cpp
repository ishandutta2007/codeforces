#include<bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  int N;
  cin >> N;
  ++N;
  vector< pair< char, int > > arr;
  for(int i = 1; i <= 8; i++) {
    if(i % 2 == 1) {

      if(i == 7) {
        for(char j = 'a'; j <= 'f'; j++) {
          if(N >= 3) {
            arr.emplace_back(j, i);
            --N;
          }
        }
        for(char j = 'h'; j >= 'g'; j--) {
          if(N >= 3) {
            arr.emplace_back(j, i);
            --N;
          }
        }
        continue;
      }

      for(char j = 'a'; j <= 'h'; j++) {
        if(N >= 3) {
          arr.emplace_back(j, i);
          --N;
        }
      }
    } else {

      if(i == 8) {
        if(N >= 3) {
          if(N >= 2) {
            arr.emplace_back('g', i);
            --N;
          }
          for(char j = 'a'; j <= 'f'; j++) {
            if(N >= 2) {
              arr.emplace_back(j, i);
              --N;
            }
          }
        }
        continue;
      }
      for(char j = 'h'; j >= 'a'; j--) {
        if(N >= 3) {
          arr.emplace_back(j, i);
          --N;
        }
      }
    }
  }

  if(arr.back().second == 8) {

  } else if(arr.back().second == 7) {
    if(arr.back().first == 'h') {
      arr.pop_back();
      arr.emplace_back('g', 7);
      arr.emplace_back('h', 7);
    } else {
      auto back = arr.back();
      arr.emplace_back(back);
      arr.back().second = 8;
    }
  } else if(arr.back().first == 'h') {
    auto back = arr.back();
    arr.emplace_back(back);
    arr.back().second++;
  } else {
    auto back = arr.back();
    arr.emplace_back(back);
    arr.back().second = 8;
  }

  arr.emplace_back('h', 8);


  for(int i = 0; i < arr.size(); i++) {
    if(i) cout << " ";
    cout << arr[i].first << arr[i].second;
  }
  cout << endl;

}