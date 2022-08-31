#include <bits/stdc++.h>

using namespace std;

vector< string > dd[1000000];
string S;
int depmax;

void rec(int &idx, int depth)
{

  depmax = max(depmax, depth);
  string T;
  while(S[idx] != ',' && idx < S.size())
    T += S[idx++];
  ++idx;
  dd[depth].push_back(T);
  int sz = 0;
  while(S[idx] != ',' && idx < S.size())
    sz = sz * 10 + S[idx++] - '0';
  ++idx;
  while(sz--) rec(idx, depth + 1);
}

int main()
{
  cin >> S;
  int idx = 0;
  while(idx < S.size()) rec(idx, 0);
  cout << depmax + 1 << endl;
  for(int i = 0; i <= depmax; i++) {
    for(int j = 0; j < dd[i].size(); j++) {
      if(j > 0) cout << " ";
      cout << dd[i][j];
    }
    cout << endl;
  }
}