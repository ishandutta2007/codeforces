#include<bits/stdc++.h>

using namespace std;

int main()
{
  int N;
  string S;

  cin >> N;
  cin >> S;

  int A = count(begin(S), end(S), 'A');
  int B = count(begin(S), end(S), 'D');

  if(A > B) {
    cout << "Anton" << endl;
  } else if(A == B) {
    cout << "Friendship" << endl;
  } else {
    cout << "Danik" << endl;
  }

}