#include<bits/stdc++.h>

using namespace std;

using int64 = long long;

int main()
{
  int N, X;

  cin >> N >> X;
  for(int i = 0; i < N; i++) {
    int A;
    cin >> A;

    if(i > 0) --X;
    X -= A;
  }

  if(X == 0) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}