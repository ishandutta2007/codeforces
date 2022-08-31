#include<bits/stdc++.h>
using namespace std;

set< int > _[200003];
set< int >* data = &_[100001];

int main()
{
  int N;

  cin >> N;
  for(int i = 0; i < N; i++) {
    int x, y;
    cin >> x >> y;
    data[y - x].insert(x);
  }
  stringstream OUT;
  for(int i = 0; i < N; i++) {
    int w;
    cin >> w;
    if(data[w].empty()) exit(puts("NO"));
    int X = *data[w].begin();
    data[w].erase(data[w].begin());
    if(data[w - 1].count(X - 1) || data[w + 1].count(X - 1)) exit(puts("NO"));
    OUT << X << " " << w + X << endl;
  }
  cout << "YES" << endl;
  cout << OUT.str();
}