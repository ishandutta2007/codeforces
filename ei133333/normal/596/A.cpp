#include<bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;
  set< int > X, Y;
  for(int i = 0; i < N; i++) {
    int x, y;
    cin >> x >> y;
    X.insert(x);
    Y.insert(y);
  }
  if(X.size() == 2 && Y.size() == 2) {
    cout << (*--X.end() - *X.begin()) * (*--Y.end() - *Y.begin()) << endl;
  } else {
    cout << -1 << endl;
  }
}