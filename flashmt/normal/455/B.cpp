#include <bits/stdc++.h>
using namespace std;

struct Trie
{
  Trie *next[26];
  int win, lose;
  
  Trie()
  {
    for (int i = 0; i < 26; i++) next[i] = NULL;
    win = lose = 0;
  }
  
  void build(string &s, int id)
  {
    if (id == s.size()) return;
    int ch = s[id] - 'a';
    if (!next[ch]) next[ch] = new Trie();
    next[ch] -> build(s, id + 1);
  }
  
  int calcWin()
  {
    for (int ch = 0; ch < 26; ch++)
      if (next[ch] && !next[ch] -> calcWin())
        win = 1;
    return win;
  }
  
  int calcLose()
  {
    int hasMove = 0;
    for (int ch = 0; ch < 26; ch++)
      if (next[ch])
      {
        hasMove = 1;
        if (!next[ch] -> calcLose())
          lose = 1;
      }
    
    if (!hasMove) lose = 1;
    return lose;
  }
};

int main()
{
  ios::sync_with_stdio(0);
  int n, k;
  string s;
  Trie trie;
  cin >> n >> k;
  while (n--)
  {
    cin >> s;
    trie.build(s, 0);
  }
  
  trie.calcWin();
  trie.calcLose();
  if (trie.win) 
  {
    if (k > 1 && !trie.lose && k % 2 == 0) cout << "Second" << endl;
    else cout << "First" << endl;
  }
  else cout << "Second" << endl;
}