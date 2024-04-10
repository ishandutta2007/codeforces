#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) ((x).size()))
typedef long long ll;
typedef long double ld;

pair<int, int> p[3];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(10);
  for (int i = 0; i < 3; i++)
    cin >> p[i].first >> p[i].second;
  sort(p, p + 3);
  int sy = min(p[0].second, min(p[1].second, p[2].second));
  int ly = max(p[0].second, max(p[1].second, p[2].second));
  cout << "3\n";
  cout << p[1].first << " " << sy << " " << p[1].first << " " << ly << "\n";
  cout << p[0].first << " " << p[0].second << " " << p[1].first << " " << p[0].second << "\n";
  cout << p[2].first << " " << p[2].second << " " << p[1].first << " " << p[2].second << "\n";
}