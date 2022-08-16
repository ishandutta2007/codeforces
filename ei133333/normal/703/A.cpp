#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N;
  cin >> N;
  int A = 0, B = 0;
  while(N--) {
    int M, C;
    cin >> M >> C;
    if(M > C) ++A;
    else if(M < C) ++B;
  }
  if(A == B) {
    cout << "Friendship is magic!^^" << endl;
  } else if(A < B) {
    cout << "Chris" << endl;
  } else {
    cout << "Mishka" << endl;
  }
}