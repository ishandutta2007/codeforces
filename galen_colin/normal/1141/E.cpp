#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void end(ll i) {
  cout << i << endl;
  exit(0);
}

int main() {
    ll h;
    ll n;
    cin >> h >> n;
    ll d[n];
    for (int i = 0; i < n; i++) cin >> d[i];

    ll minc = 0, cur = 0;
    for (int i = 0; i < n; i++) {
      cur += d[i];
      minc = min(minc, cur);
    }

    //case: will never end
    if (minc + h > 0 && cur >= 0) end(-1);

    if (h + minc > 0) { //case: loop around 1+ times
      cur *= -1;
      ll mov = n * ((h + minc) / cur);
      h -= cur * floor((h + minc) / cur);
      while (h > 0) {
        for (int i = 0; i < n; i++) {
          mov++;
          h += d[i];
          if (h <= 0) end(mov);
        }
      }
    } else {
      ll mov = 0;
      for (int i = 0; i < n; i++) {
        mov++;
        h += d[i];
        if (h <= 0) end(mov);
      }
    }
    
}