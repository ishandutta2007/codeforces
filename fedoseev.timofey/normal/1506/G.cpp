#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = s.size();
    vector<deque<int> > pos(26);
    for (int i = 0; i < n; ++i) {
      pos[s[i] - 'a'].push_back(i);
    }
    string ans;
    int uk = 0;
    while (true) {
      int need = n;
      for (int i = 0; i < 26; ++i) {
        if (pos[i].size() >= 1) {
          need = min(need, pos[i].back()); 
        }
      }
      int id = 26;
      for (int i = 25; i >= 0; --i) {
        if (!pos[i].empty() && pos[i].front() <= need) {
          id = i;
          break;
        }
      }
      if (id == 26) break;
      ans += char('a' + id);
      int who = pos[id].front();
      pos[id].clear();
      for (int j = uk; j <= who; ++j) {
        int ch = s[j] - 'a';
        if (!pos[ch].empty() && pos[ch].front() == j) {
          pos[s[j] - 'a'].pop_front();
        }
      }
      uk = who + 1;
    }
    cout << ans << '\n';
  }  
}