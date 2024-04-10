#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>

typedef long long ll;

using namespace std;

const ll INF = 4294967296;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  stack <ll> s;
  s.push(1);
  int q;
  cin >> q;
  ll x = 0;
  while (q--) {
    string str;
    cin >> str;
    if (str == "add")
      x = min(x + s.top(), INF);
    else if (str == "end")
      s.pop();
    else {
      ll val;
      cin >> val;
      s.push(min(val * s.top(), INF));
    }
  }
  if (x >= INF)
    cout << "OVERFLOW!!!";
  else
    cout << x;
  return 0;
}