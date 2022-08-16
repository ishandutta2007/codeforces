#include<bits/stdc++.h>

using namespace std;

int main()
{
  int N;
  string S[100];

  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> S[i];

    bool found = false;
    for(int j = 0; j < i; j++) {
      if(S[i] == S[j]) found = true;
    }

    if(found) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
}