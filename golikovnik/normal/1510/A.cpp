//  Copyright 2021 Nikita Golikov

#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

template <class A, class B>
bool smin(A &x, B &&y) {
  if (y < x) {
    x = y;
    return true;
  }
  return false;
}

template <class A, class B>
bool smax(A &x, B &&y) {
  if (x < y) {
    x = y;
    return true;
  }
  return false;
}

string s;
int sPtr;

vector<string> parseExpr();

vector<string> makeString(string const& str) {
  int n = int(str.size());
  vector<string> ans(3);
  for (auto& t : ans) t.assign(4 + n, ' ');
  for (int r = 0; r < 3; ++r) ans[r][0] = ans[r][3 + n] = '+';
  for (int c = 1; c < 3 + n; ++c) ans[0][c] = ans[2][c] = '-';
  for (int i = 0; i < n; ++i) ans[1][2 + i] = str[i];
  return ans;
}

vector<string> makePlus(vector<string> const& atom) {
  int n = int(atom.size());
  int m = int(atom[0].size());
  vector<string> ans(n + 2);
  for (auto& t : ans) t.assign(m + 6, ' ');
  for (int r = 2; r < n + 1; ++r) ans[r][0] = ans[r][m + 5] = '|';
  ans[1][0] = ans[1][m + 5] = ans[n + 1][0] = ans[n + 1][m + 5] = '+';
  for (int c = 2; c < m + 5; ++c) ans[n + 1][c] = '-';
  ans[n + 1][1] = '<';
  ans[1][1] = '-';
  ans[1][2] = '>';
  ans[1][m + 4] = '>';
  ans[1][m + 3] = '-';
  for (int r = 0; r < n; ++r) {
    for (int c = 0; c < m; ++c) {
      ans[r][c + 3] = atom[r][c];
    }
  }
  return ans;
}

vector<string> makeQuestion(vector<string> const& atom) {
  int n = int(atom.size());
  int m = int(atom[0].size());
  vector<string> ans(3 + n);
  for (auto& t : ans) t.assign(6 + m, ' ');
  ans[1][0] = ans[1][m + 5] = ans[4][0] = ans[4][m + 5] = '+';
  ans[4][1] = '-';
  ans[4][2] = '>';
  ans[4][m + 4] = '>';
  ans[4][m + 3] = '-';
  ans[1][m + 4] = '>';
  for (int c = 1; c < m + 4; ++c) ans[1][c] = '-';
  for (int r = 2; r < 4; ++r) ans[r][0] = ans[r][m + 5] = '|';
  for (int r = 0; r < n; ++r) {
    for (int c = 0; c < m; ++c) {
      ans[r + 3][c + 3] = atom[r][c];
    }
  }
  return ans;
}

vector<string> makeStar(vector<string> const& atom) {
  int n = int(atom.size());
  int m = int(atom[0].size());
  vector<string> ans(n + 5);
  for (auto& t : ans) t.assign(m + 6, ' ');
  for (int r = 2; r < n + 4; ++r) ans[r][0] = ans[r][m + 5] = '|';
  ans[1][0] = ans[1][m + 5] = ans[n + 4][0] = ans[n + 4][m + 5] = ans[4][0] = ans[4][m + 5] = '+';
  ans[n + 4][1] = '<';
  for (int c = 2; c < m + 5; ++c) ans[n + 4][c] = '-';
  for (int c = 1; c < m + 4; ++c) ans[1][c] = '-';
  ans[1][m + 4] = '>';
  ans[4][1] = '-';
  ans[4][2] = '>';
  ans[4][m + 4] = '>';
  ans[4][m + 3] = '-';
  for (int r = 0; r < n; ++r) {
    for (int c = 0; c < m; ++c) {
      ans[3 + r][3 + c] = atom[r][c];
    }
  }
  return ans;
}

vector<string> joinAtoms(vector<vector<string>> const& atoms) {
  if (atoms.size() == 1) return atoms[0];
  int h = 0;
  for (auto& at : atoms) smax(h, int(at.size()));
  int w = 0;
  for (auto& at : atoms) {
    w += int(at[0].size());
    w += 2;
  }
  w -= 2;
  vector<string> ans(h);
  for (auto& t : ans) t.assign(w, ' ');
  int st = 0;
  int natoms = int(atoms.size());
  for (int i = 0; i < natoms; ++i) {
    auto& at = atoms[i];
    int n = int(at.size());
    int m = int(at[0].size());
    for (int r = 0; r < n; ++r) {
      for (int c = 0; c < m; ++c) {
        ans[r][c + st] = at[r][c];
      }
    }
    if (i + 1 == natoms) break;
    st += m;
    ans[1][st] = '-';
    ans[1][st + 1] = '>';
    st += 2;
  }
  return ans;
}

vector<string> joinTerms(vector<vector<string>> const& terms) {
  if (terms.size() == 1) return terms[0];
  int w = 0;
  for (auto& t : terms) smax(w, int(t[0].size()));
  w += 6;
  int h = 0;
  for (auto& t : terms) {
    h += int(t.size());
    h += 1;
  }
  h -= 1;
  vector<string> ans(h);
  for (auto& t : ans) t.assign(w, ' ');
  int st = 0;
  int nterms = int(terms.size());
  for (int i = 0; i < nterms; ++i) {
    auto& tt = terms[i];
    ans[st + 1][0] = '+';
    ans[st + 1][1] = '-';
    ans[st + 1][2] = '>';
    int n = int(tt.size());
    int m = int(tt[0].size());
    for (int r = 0; r < n; ++r) {
      for (int c = 0; c < m; ++c) {
        ans[st + r][3 + c] = tt[r][c];
      }
    }
    for (int c = m + 3; c < w; ++c) ans[st + 1][c] = '-';
    ans[st + 1][w - 1] = '+';
    ans[st + 1][w - 2] = '>';
    if (i + 1 == nterms) break;
    for (int r = 0; r < n; ++r) {
      ans[st + 2 + r][0] = ans[st + 2 + r][w - 1] = '|';
    }
    st += n + 1;
  }
  return ans;
}

vector<string> parseTerm() {
  vector<vector<string>> atoms;
  string last;
  while (sPtr < int(s.size()) && s[sPtr] != '|' && s[sPtr] != ')') {
    auto ch = s[sPtr];
    if ('A' <= ch && ch <= 'Z') {
      last += ch;
      sPtr++;
      continue;
    }
    if (ch == '(') {
      sPtr++;
      if (!last.empty()) {
        atoms.push_back(makeString(last));
      }
      last = "";
      atoms.push_back(parseExpr());
      sPtr++;
      continue;
    }
    if (!last.empty()) {
      auto plast = last.substr(0, last.size() - 1);
      if (!plast.empty()) {
        atoms.push_back(makeString(plast));
      }
      atoms.push_back(makeString(string(1, last.end()[-1])));
      last = "";
    }
    sPtr++;
    if (ch == '+') {
      auto natom = makePlus(atoms.back());
      atoms.pop_back();
      atoms.push_back(natom);
      continue;
    }
    if (ch == '?') {
      auto natom = makeQuestion(atoms.back());
      atoms.pop_back();
      atoms.push_back(natom);
      continue;
    }
    auto natom = makeStar(atoms.back());
    atoms.pop_back();
    atoms.push_back(natom);
  }
  if (!last.empty()) {
    atoms.push_back(makeString(last));
  }
  return joinAtoms(atoms);
}

vector<string> parseExpr() {
  vector<vector<string>> terms;
  while (sPtr < int(s.size())) {
    terms.push_back(parseTerm());
    if (sPtr < int(s.size())) {
      if (s[sPtr] == '|') {
        sPtr++;
      } else {
        break;
      }
    }
  }
  return joinTerms(terms);
}

vector<string> parseInput() {
  auto result = parseExpr();
  int n = int(result.size());
  int m = int(result[0].size());
  vector<string> ans(n);
  for (auto& t : ans) t.assign(m + 6, ' ');
  ans[1][0] = 'S';
  ans[1][1] = '-';
  ans[1][2] = '>';
  ans[1][m + 5] = 'F';
  ans[1][m + 4] = '>';
  ans[1][m + 3] = '-';
  for (int r = 0; r < n; ++r) {
    for (int c = 0; c < m; ++c) {
      ans[r][3 + c] = result[r][c];
    }
  }
  return ans;
}

int main() {
#ifdef GOLIKOV
  assert(freopen("in", "rt", stdin));
  auto _clock_start = chrono::high_resolution_clock::now();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> s;
  auto result = parseInput();
  cout << result.size() << ' ' << result[0].size() << '\n';
  for (auto const& t : result) cout << t << '\n';

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}