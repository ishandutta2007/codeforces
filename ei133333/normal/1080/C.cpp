#include<bits/stdc++.h>

using namespace std;

using int64 = long long;
const int INF = 1 << 30;

int main() {
  int T;
  cin >> T;

  auto solveEven = [&](int64 X) {
    if(X < 0) return 0LL;
    return X / 2 + 1;
  };

  auto solveWhite = [&](int64 x1, int64 x2, int64 y1, int64 y2) {

    int64 evenX = solveEven(x2 - 1) - solveEven(x1 - 1);
    int64 oddX = (x2 - x1) - evenX;


    int64 evenY = solveEven(y2 - 1) - solveEven(y1 - 1);
    int64 oddY = (y2 - y1) - evenY;

    return evenX * evenY + oddX * oddY;
  };

  while(T--) {
    int H, W;
    cin >> H >> W;
    int X1, Y1, X2, Y2;
    cin >> X1 >> Y1 >> X2 >> Y2;
    --X1, --Y1, --X2, --Y2;
    int X3, Y3, X4, Y4;
    cin >> X3 >> Y3 >> X4 >> Y4;
    --X3, --Y3, --X4, --Y4;

    vector< int64 > XS, YS;
    auto add = [&](int64 x, int64 y) {
      for(int i = -2; i <= 2; i++) {
        XS.emplace_back(min(W - 1LL, max(x + i, 0LL)));
        YS.emplace_back(min(H - 1LL, max(y + i, 0LL)));
      }
    };
    add(X1, Y1);
    add(X2, Y2);
    add(X3, Y3);
    add(X4, Y4);
    XS.emplace_back(0);
    XS.emplace_back(W);
    YS.emplace_back(0);
    YS.emplace_back(H);
    sort(begin(XS), end(XS));
    XS.erase(unique(begin(XS), end(XS)), end(XS));
    sort(begin(YS), end(YS));
    YS.erase(unique(begin(YS), end(YS)), end(YS));
    vector< vector< int > > fill(XS.size(), vector< int >(YS.size(), -1));
    for(int i = 0; i < XS.size(); i++) {
      for(int j = 0; j < YS.size(); j++) {
        if(X1 <= XS[i] && XS[i] <= X2 && Y1 <= YS[j] && YS[j] <= Y2) {
          fill[i][j] = 0;
        }
      }
    }
    for(int i = 0; i < XS.size(); i++) {
      for(int j = 0; j < YS.size(); j++) {
        if(X3 <= XS[i] && XS[i] <= X4 && Y3 <= YS[j] && YS[j] <= Y4) {
          fill[i][j] = 1;
        }
      }
    }

    int64 white = 0, black = 0;
    for(int i = 0; i + 1 < XS.size(); i++) {
      for(int j = 0; j + 1 < YS.size(); j++) {
        if(fill[i][j] == 0) {
          white += (XS[i + 1] - XS[i]) * (YS[j + 1] - YS[j]);
        } else if(fill[i][j] == 1) {
          black += (XS[i + 1] - XS[i]) * (YS[j + 1] - YS[j]);
        } else {
          int64 all = (XS[i + 1] - XS[i]) * (YS[j + 1] - YS[j]);
          auto it = solveWhite(XS[i], XS[i + 1], YS[j], YS[j + 1]);
          white += it;
          black += all - it;
        }
      }
    }
    cout << white << " " << black << endl;
  }
}