#include<bits/stdc++.h>
using namespace std;
typedef pair< int, int > Pi;
int main()
{
  int N;
  string S;
  map< Pi, int > multi;
  map< int, int > single;

  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> S;
    set< char > c;
    for(int i = 'a'; i <= 'z'; i++) {
      if(count(S.begin(), S.end(), i) > 0) c.insert(i);
    }
    if(c.size() == 1) {
      single[*c.begin()] += count(S.begin(), S.end(), *c.begin());
    } else if(c.size() == 2) {
      multi[Pi(*c.begin(), *--c.end())] +=
        count(S.begin(), S.end(), *c.begin()) +
        count(S.begin(), S.end(), *--c.end());
    }
  }

  int ret = 0;
  if(single.size() >= 1) {
    ret += (--single.end()) -> second;
  }
  if(single.size() >= 2) {
    for(auto& e : single) {
      for(auto& e2 : single) {
        if(e == e2) continue;
        ret = max(ret, e.second + e2.second);
      }
    }
  }
  for(auto& e : multi) {
    ret = max(ret, e.second + single[e.first.first] + single[e.first.second]);
  }
  cout << ret << endl;
}