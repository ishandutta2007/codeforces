#include<bits/stdc++.h>

using namespace std;

int main()
{
  int N, P[100];
  string temp = "aiueoy";

  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> P[i];
  }

  cin.ignore();

  for(int i = 0; i < N; i++) {
    string K;
    getline(cin, K);
    int sum = 0;
    for(int j = 0; j < K.size(); j++) {
      if(temp.find(K[j]) != string::npos) ++sum;
    }
    if(P[i] != sum) {
      cout << "NO" << endl;
      return(0);
    }
  }

  cout << "YES" << endl;
}