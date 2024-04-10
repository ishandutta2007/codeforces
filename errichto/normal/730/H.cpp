#include <bits/stdc++.h>

using namespace std;

vector<string> ok, nie;

string licz() {
  int l = 0;
  for (const string& s : ok) {
    l = (int) s.length();
  }
  for (const string& s : ok) {
    if (l != (int) s.length()) {
      throw 1;
    }
  }
  string s;
  for (int i = 0; i < l; i++) {
    set<char> all;
    for (const string& s : ok) {
      all.insert(s[i]);
    }
    if ((int) all.size() != 1) {
      s.push_back('?');
    } else {
      s.push_back(*all.begin());
    }
  }
  return s;
}

int n, m;
char buf[1004];
string wsio[105];
bool jestok[105];

bool match(const string& s, const string& t) {
  if (s.length() != t.length()) return false;
  for (int i = 0; i < (int) s.length(); i++) {
    if (s[i] == '?') continue;
    if (s[i] != t[i]) return false;
  }
  return true;
}

bool sprawdz(const string& s) {
  for (int i = 1; i <= n; i++) {
    if (match(s, wsio[i]) != jestok[i]) {
      return false;
    }
  }
  return true;
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%s", buf);
    wsio[i] = buf;
  }
  while (m--) {
    int a;
    scanf("%d", &a);
    jestok[a] = true;
  }
  for (int i = 1; i <= n; i++) {
    if (jestok[i]) ok.push_back(wsio[i]);
    else nie.push_back(wsio[i]);
  }
  try {
    const string& s = licz();
    // printf("s = %s\n", s.c_str());
    if (sprawdz(s)) {
      printf("Yes\n%s\n", s.c_str());
      return 0;
    }
  } catch (int i) {
    // pass.
  }
  printf("No\n");
  return 0;
}