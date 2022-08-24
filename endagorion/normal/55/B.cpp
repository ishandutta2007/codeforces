#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

vector<vector <long long> > vsum(const vector<vector<long long> > &a) {
  vector<vector<long long> > result;
  for (int t = 0; t < a.size(); ++t) 
  for (int i = 0; i < a[t].size(); ++i) {
    for (int j = i+1; j < a[t].size(); ++j) {
      vector <long long> piece;
      for (int k = 0; k < a[t].size(); ++k) {
        if (i != k && j != k) piece.push_back(a[t][k]);
      }
      piece.push_back(a[t][i] + a[t][j]);
      result.push_back(piece);
    }
  }
  return result;
}

vector<vector <long long> > vmul(const vector<vector<long long> > &a) {
  vector<vector<long long> > result;
  for (int t = 0; t < a.size(); ++t) 
  for (int i = 0; i < a[t].size(); ++i) {
    for (int j = i+1; j < a[t].size(); ++j) {
      vector <long long> piece;
      for (int k = 0; k < a[t].size(); ++k) {
        if (i != k && j != k) piece.push_back(a[t][k]);
      }
      piece.push_back(a[t][i] * a[t][j]);
      result.push_back(piece);
    }
  }
  return result;
}


int main() {
  vector<vector <long long> > a(1, vector <long long>(4) );
  for (int i = 0; i < 4; ++i) {
    cin >> a[0][i];
  }
  for (int i = 0; i < 3; ++i) {
    string c;
    cin >> c;
    if (c == "+") {
      a = vsum(a);
    } else {
      a = vmul(a);
    }
  }
  long long ans = 1e18;
  for (int i = 0; i < a.size(); ++i) {
    ans = min(ans, a[i][0]);
  }
  cout << ans << '\n';
  return 0;
}