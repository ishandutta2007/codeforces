#include<bits/stdc++.h>
using namespace std;

int main()
{
  const int Point[] = {500, 1000, 1500, 2000, 2500};
  int m[5], w[5];

  for(int i = 0; i < 5; i++) {
    cin >> m[i];
  }
  for(int i = 0; i < 5; i++) {
    cin >> w[i];
  }

  int ret = 0;
  for(int i = 0; i < 5; i++) {
    ret += max(Point[i] * 3 / 10, Point[i] - (Point[i] * m[i]) / 250 - 50 * w[i]);
  }
 
  int hs, hu;
  cin >> hs >> hu;

  cout << ret + hs * 100 - hu * 50 << endl;
}