#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

string a[302][302];
string b[302][302];

vector<pair<pair<int, int>, pair<int, int> > > ans;

bool debug = false;

int main() {
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      cin >> a[i][j];
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      cin >> b[i][j];
  
  if (debug) { 
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j)
        cout << a[i][j] << " ";
      cout << endl;
    }
    cout << "--------" << endl;
  }

  // Step - 1
  for (int i = 0; i < a[0][0].size(); ++i) {
    ans.push_back({{0, 0}, {n - 1, 0}});
  }
  a[n - 1][0] = a[0][0] + a[n - 1][0];
  a[0][0] = "";

  for (int i = 0; i < a[n - 1][m - 1].size(); ++i) {
    ans.push_back({{n - 1, m - 1}, {0, m - 1}});
  }
  a[0][m - 1] = a[n - 1][m - 1] + a[0][m - 1];
  a[n - 1][m - 1] = "";

  if (debug) { 
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j)
        cout << a[i][j] << " ";
      cout << endl;
    }
    cout << "--------" << endl;
  }

  // Step - 2
  for (int i = 0; i < n; ++i) {
    reverse(a[i][0].begin(), a[i][0].end());
    reverse(a[i][m - 1].begin(), a[i][m - 1].end());
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 1; j < m - 1; ++j) {
      reverse(a[i][j].begin(), a[i][j].end());
      for (char c : a[i][j]) {
        if (c == '0') {
          a[i][0] += '0';
          ans.push_back({{i, j}, {i, 0}});
        } else {
          a[i][m - 1] += '1';
          ans.push_back({{i, j}, {i, m - 1}});
        }
      }
      a[i][j] = "";
    }
  }
  for (int i = 0; i < n; ++i) {
    reverse(a[i][0].begin(), a[i][0].end());
    reverse(a[i][m - 1].begin(), a[i][m - 1].end());
  }
  if (debug) { 
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j)
        cout << a[i][j] << " ";
      cout << endl;
    }
    cout << "--------" << endl;
  }

  // Step - 3
  reverse(a[0][0].begin(), a[0][0].end());
  reverse(a[n - 1][0].begin(), a[n - 1][0].end());
  reverse(a[0][m - 1].begin(), a[0][m - 1].end());
  reverse(a[n - 1][m - 1].begin(), a[n - 1][m - 1].end());
  for (int i = 1; i < n - 1; ++i) {
    reverse(a[i][0].begin(), a[i][0].end());
    for (char c : a[i][0]) {
      if (c == '0') {
        a[0][0] += '0';
        ans.push_back({{i, 0}, {0, 0}});
      } else {
        a[n - 1][0] += '1';
        ans.push_back({{i, 0}, {n - 1, 0}});
      }
    }
    a[i][0] = "";

    reverse(a[i][m - 1].begin(), a[i][m - 1].end());
    for (char c : a[i][m - 1]) {
      if (c == '0') {
        a[0][m - 1] += '0';
        ans.push_back({{i, m - 1}, {0, m - 1}});
      } else {
        a[n - 1][m - 1] += '1';
        ans.push_back({{i, m - 1}, {n - 1, m - 1}});
      }
    }
    a[i][m - 1] = "";
  }
  reverse(a[0][0].begin(), a[0][0].end());
  reverse(a[n - 1][0].begin(), a[n - 1][0].end());
  reverse(a[0][m - 1].begin(), a[0][m - 1].end());
  reverse(a[n - 1][m - 1].begin(), a[n - 1][m - 1].end());
  if (debug) { 
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j)
        cout << a[i][j] << " ";
      cout << endl;
    }
    cout << "--------" << endl;
  }

  // Step - 4
  reverse(a[0][0].begin(), a[0][0].end());
  reverse(a[n - 1][m - 1].begin(), a[n - 1][m - 1].end());
  reverse(a[n - 1][0].begin(), a[n - 1][0].end());
  for (char c : a[n - 1][0]) {
    if (c == '0') {
      a[0][0] += '0';
      ans.push_back({{n - 1, 0}, {0, 0}});
    } else {
      a[n - 1][m - 1] += '1';
      ans.push_back({{n - 1, 0}, {n - 1, m - 1}});
    }
  }
  a[n - 1][0] = "";
  reverse(a[0][m - 1].begin(), a[0][m - 1].end());
  for (char c : a[0][m - 1]) {
    if (c == '0') {
      a[0][0] += '0';
      ans.push_back({{0, m - 1}, {0, 0}});
    } else {
      a[n - 1][m - 1] += '1';
      ans.push_back({{0, m - 1}, {n - 1, m - 1}});
    }
  }
  a[0][m - 1] = "";
  reverse(a[0][0].begin(), a[0][0].end());
  reverse(a[n - 1][m - 1].begin(), a[n - 1][m - 1].end());
  if (debug) { 
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j)
        cout << a[i][j] << " ";
      cout << endl;
    }
    cout << "--------" << endl;
  }

  // Step - 5
  for (int i = 0; i < n - 1; ++i) {
    for (int j = 1; j < m; ++j) {
      for (int t = b[i][j].size() - 1; t >= 0; --t) {
        if (b[i][j][t] == '0') {
          if (i != 0)
            ans.push_back({{0, 0}, {i, 0}});
          ans.push_back({{i, 0}, {i, j}});
          a[0][0].pop_back();
        } else {
          if (j != m - 1)
            ans.push_back({{n - 1, m - 1}, {n - 1, j}});
          ans.push_back({{n - 1, j}, {i, j}});
          a[n - 1][m - 1].pop_back();
        }
      }
      a[i][j] = b[i][j];
    }
  }
  if (debug) { 
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j)
        cout << a[i][j] << " ";
      cout << endl;
    }
    cout << "--------" << endl;
  }

  // Step - 6
  string what = b[n - 1][0];
  for (int i = 0; i < n - 1; ++i) {
    what += b[i][0];
  }
  for (int j = 1; j < m; ++j) {
    what += b[n - 1][j];
  }

  for (int t = what.size() - 1; t >= 0; --t) {
    if (what[t] == '0') {
      ans.push_back({{0, 0}, {n - 1, 0}});
      a[0][0].pop_back();
    } else {
      ans.push_back({{n - 1, m - 1}, {n - 1, 0}});
      a[n - 1][m - 1].pop_back();
    }
  }
  a[n - 1][0] = what;
  if (debug) { 
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j)
        cout << a[i][j] << " ";
      cout << endl;
    }
    cout << "--------" << endl;
  }

  // Step - 7
  for (int j = m - 1; j > 0; --j) {
    for (int t = 0; t < b[n - 1][j].size(); ++t) {
      ans.push_back({{n - 1, 0}, {n - 1, j}});
      a[n - 1][0].pop_back();
    }
    a[n - 1][j] = b[n - 1][j];
  }
  for (int i = n - 2; i >= 0; --i) {
    for (int t = 0; t < b[i][0].size(); ++t) {
      ans.push_back({{n - 1, 0}, {i, 0}});
      a[n - 1][0].pop_back();
    }
    a[i][0] = b[i][0];
  }
  if (debug) { 
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j)
        cout << a[i][j] << " ";
      cout << endl;
    }
    cout << "--------" << endl;
  }

  // cout << ans.size() << endl;
  printf("%d\n", (int) ans.size());
  for (pair<pair<int, int>, pair<int, int> > p : ans)
    printf("%d %d %d %d\n", p.first.first + 1, p.first.second + 1, p.second.first + 1, p.second.second + 1);
    // cout << p.first.first + 1 << " " << p.first.second + 1 << " " << p.second.first + 1 << " " << p.second.second + 1 << endl;

  return 0;
}