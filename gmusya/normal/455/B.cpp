#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector <int> win, lose;

struct trie {
  struct vertex {
    vector <int> nex = vector <int>(26, -1);
    vertex() {};
  };
  vector <vertex> t = vector <vertex>(1);
  trie() {};
  void add(int v, int pos, string &s) {
    if (pos == s.size())
      return;
    int val = s[pos] - 'a';
    if (t[v].nex[val] == -1) {
      t[v].nex[val] = t.size();
      t.push_back({});
    }
    add(t[v].nex[val], pos + 1, s);
  }
  void add(string &s) {
    add(0, 0, s);
  }
  void play(int v) {
    int cnt = 0;
    for (int i = 0; i < 26; i++)
      if (t[v].nex[i] == -1)
        cnt++;
    if (cnt == 26) {
      win[v] = false;
      lose[v] = true;
      return;
    }
    for (int i = 0; i < 26; i++) {
      if (t[v].nex[i] == -1)
        continue;
      play(t[v].nex[i]);
      win[v] |= (!win[t[v].nex[i]]);
      lose[v] |= (!lose[t[v].nex[i]]);
    }
  }
};

int main() {
  int n, k;
  cin >> n >> k;
  vector <string> s(n);
  for (int i = 0; i < n; i++)
    cin >> s[i];
  trie tr;
  for (int i = 0; i < n; i++)
    tr.add(s[i]);
  int sz = tr.t.size();
  win.resize(sz), lose.resize(sz);
  tr.play(0);
  if (!win[0]) {
    cout << "Second";
  } else if (win[0] && lose[0]) {
    cout << "First";
  } else if (k % 2) {
    cout << "First";
  } else {
    cout << "Second";
  }
  return 0;
}