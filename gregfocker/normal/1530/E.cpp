#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int eval(string pat) {
  int m = (int) pat.size();
  vector<int> ps(m, 0);
  int j = 0, sol = 0;
  for (int i = 1; i < m; i++) {
    while (j && pat[i] != pat[j]) {
      j = ps[j - 1];
    }
    if (pat[i] == pat[j]) {
      j++;
    }
    ps[i] = j;
    sol = max(sol, ps[i]);
  }
  return sol;
}

string brute(string s) {
  sort(s.begin(), s.end());
  string sol = s;
  while (next_permutation(s.begin(), s.end())) {
    if (eval(s) < eval(sol)) {
      sol = s;
    }
  }
  return sol;
}

string tos(vector<int> v) {
  string sol;
  for (auto &i : v) {
    assert(0 <= i && i < 26);
    sol += (char) ('a' + i);
  }
  return sol;
}

bool ok(int others, int me, bool lastME) {
  if (lastME) {
    return others >= me;
  } else {
    return others >= me - 1;
  }
}

string solve(string s) {
  if (s.empty()) {
    return s;
  }
  vector<int> f(26, 0);
  for (auto &x : s) {
    f[x - 'a']++;
  }
  int cdif = 0;
  for (int i = 0; i < 26; i++) {
    cdif += (f[i] > 0);
  }
  if (cdif == 1) {
    return s;
  }
  for (int i = 0; i < 26; i++) {
    if (f[i] == 1) {
      vector<int> sol = {i};
      f[i]--;
      for (int j = 0; j < 26; j++) {
        for (int k = 0; k < f[j]; k++) {
          sol.push_back(j);
        }
      }
      return tos(sol);
    }
  }
  for (int i = 0; i < 26; i++) {
    assert(f[i] == 0 || f[i] >= 2);
  }
  vector<int> pivs;
  for (int i = 0; i < 26; i++) {
    if (f[i] >= 2) {
      pivs.push_back(i);
    }
  }
  assert((int) pivs.size() >= 2);

  { /// the first ones are equal?
    vector<int> ord;
    for (int i = 0; i < 26; i++) {
      if (i == pivs[0]) continue;
      for (int k = 0; k < f[i]; k++) {
        ord.push_back(i);
      }
    }
    reverse(ord.begin(), ord.end());

    int x = pivs[0];
    f[x]--;
    f[x]--;

    int others = (int) s.size() - 2 - f[x], me = f[x];

    vector<int> sol = {x, x};
    if (others >= me) {
      for (int step = 3; step <= (int) s.size(); step++) {
        if (sol.back() != x && me >= 1 && ok(others, me - 1, 1)) {
          sol.push_back(x);
          me--;
        } else {
          assert(others - 1 >= 0);
          assert(ok(others - 1, me, 0));
          sol.push_back(ord.back());
          ord.pop_back();
        }
      }
    ///  cout << "lol\n";
      return tos(sol);
    }
  }

  for (int i = 0; i < 26; i++) {
    f[i] = 0;
  }
  for (auto &x : s) {
    f[x - 'a']++;
  }
  /// the first ones are different!
  if ((int) pivs.size() == 2) {
    vector<int> sol = {pivs[0]};
    f[pivs[0]]--;
    for (auto &i : pivs) {
      if (i != pivs[0]) {
        for (int k = 0; k < f[i]; k++) {
          sol.push_back(i);
        }
      }
    }
    for (int k = 0; k < f[pivs[0]]; k++) {
      sol.push_back(pivs[0]);
    }
    return tos(sol);
  }
  vector<int> sol = {pivs[0], pivs[1]};
  f[pivs[0]]--;
  f[pivs[1]]--;

  for (int k = 0; k < f[pivs[0]]; k++) {
    sol.push_back(pivs[0]);
  }
  f[pivs[2]]--;
  sol.push_back(pivs[2]);

  for (auto &i : pivs) {
    if (i != pivs[0]) {
      for (int k = 0; k < f[i]; k++) {
        sol.push_back(i);
      }
    }
  }
  return tos(sol);
}

int lenmax = 14;
char chmax = 'c';
int done = 0;

void test(string s) {
  cout << s << " : " << solve(s) << " and " << brute(s) << "\n";
  assert(brute(s) == solve(s));
  done++;
  if (done % 10 == 0) {
    cout << done << " !!!!!!!\n";
  }
  if ((int) s.size() == lenmax) {
    return;
  }
  char bg;
  if (s.empty()) {
    bg = 'a';
  } else{
    bg = s.back();
  }
  for (char c = bg; c <= chmax; c++) {
    test(s + c);
  }
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

 /// freopen ("input", "r", stdin);
/**  test("");
  cout << "done = " << done << "\n";
  exit(0);**/

  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    cout << solve(s) << "\n";
  }
}


/**

**/