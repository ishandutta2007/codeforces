#include <bits/stdc++.h>

using namespace std;

int main()
{
  int H1, A1, C1;
  int H2, A2;

  cin >> H1 >> A1 >> C1;
  cin >> H2 >> A2;

  for(int use = 0;; use++) {

    int h1 = H1 + C1 * use - A2 * use, h2 = H2;
    int turn = use;
    while(h1 > 0 && h2 > 0) {
      h2 -= A1;
      if(h2 > 0) h1 -= A2;
      ++turn;
    }

    if(h1 > 0) {
      cout << turn << endl;
      for(int i = 0; i < use; i++) cout << "HEAL" << endl;
      for(int i = 0; i < turn - use; i++) cout << "STRIKE" << endl;
      return(0);
    }
  }


}