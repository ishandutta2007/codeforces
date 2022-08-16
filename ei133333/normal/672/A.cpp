#include<bits/stdc++.h>
using namespace std;

int main()
{
  string S = "";
  for(int i = 1; S.size() < 1500; i++) {
    stringstream sss;
    sss << i;
    S += sss.str();
  }
  int N;
  cin >> N;
  cout << S[N - 1] << endl;
}