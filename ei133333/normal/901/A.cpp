#include <bits/stdc++.h>

using namespace std;

int main()
{
  int H, V[100001];

  cin >> H;
  ++H;
  for(int i = 0; i < H; i++) {
    cin >> V[i];
  }

  int found = -1;
  for(int i = 0; i + 1 < H; i++) {
    if(V[i] >= 2 && V[i + 1] >= 2) {
      found = i + 1;
    }
  }

  if(~found) {

    vector< int > latte[100001];

    int ptr = 0;
    for(int i = 0; i < H; i++) {
      while(V[i] > 0) {
        latte[i].push_back(ptr++);
        --V[i];
      }
    }

    cout << "ambiguous" << endl;
    for(int i = 0; i < H; i++) {
      for(auto &p : latte[i]) {
        cout << (i == 0 ? 0 : latte[i - 1].back() + 1) << " ";
      }
    }
    cout << endl;
    for(int i = 0; i < H; i++) {
      bool enable = false;
      for(int j = 0; j < latte[i].size(); j++) {
        if(found == i && !enable) {
          cout << latte[i - 1].back() + 1 << " ";
          latte[i - 1].pop_back();
          cout << latte[i - 1].back() + 1 << " ";
          ++j;
          enable = true;
        } else {
          cout << (i == 0 ? 0 : latte[i - 1].back() + 1) << " ";
        }
      }

    }
    cout << endl;

  } else {
    cout << "perfect" << endl;
  }
}