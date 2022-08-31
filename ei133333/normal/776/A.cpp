#include<bits/stdc++.h>

using namespace std;

int main()
{
  string S, T;
  int N;

  cin >> S >> T;
  cin >> N;

  cout << S << " " << T << endl;

  for(int i = 0; i < N; i++) {
    string A, B;
    cin >> A >> B;


    if(S == A) {
      S = B;
    } else if(T == A) {
      T = B;
    }

    cout << S << " " << T << endl;
  }
}