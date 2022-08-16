#include<bits/stdc++.h>

using namespace std;

using int64 = long long;
using vi = vector< int64 >;

struct TrieNode
{
  int nxt[3];

  int exist;
  vector< int > accept;

  TrieNode() : exist(0)
  {
    memset(nxt, -1, sizeof(nxt));
  }
};

struct Trie
{
  vector< TrieNode > nodes;
  int root;

  Trie() : root(0)
  {
    nodes.push_back(TrieNode());
  }

  virtual void direct_action(int node, int id) {}

  virtual void child_action(int node, int child, int id) {}

  void update_direct(int node, int id)
  {
    nodes[node].accept.push_back(id);
    direct_action(node, id);
  }

  void update_child(int node, int child, int id)
  {
    ++nodes[node].exist;
    child_action(node, child, id);
  }

  void add(const string &str, int str_index, int node_index, int id)
  {
    if(str_index == str.size()) {
      update_direct(node_index, id);
    } else {
      const int c = str[str_index] - '0';
      if(nodes[node_index].nxt[c] == -1) {
        nodes[node_index].nxt[c] = (int) nodes.size();
        nodes.push_back(TrieNode());
      }
      add(str, str_index + 1, nodes[node_index].nxt[c], id);
      update_child(node_index, nodes[node_index].nxt[c], id);
    }
  }

  void add(const string &str, int id)
  {
    add(str, 0, 0, id);
  }

  void add(const string &str)
  {
    add(str, nodes[0].exist);
  }

  int size()
  {
    return (nodes[0].exist);
  }

  int nodesize()
  {
    return ((int) nodes.size());
  }
};

struct Aho_Corasick : Trie
{
  static const int FAIL = 2;
  vector< int > correct;

  Aho_Corasick() : Trie() {}

  void build()
  {
    correct.resize(nodes.size());
    for(int i = 0; i < nodes.size(); i++) {
      correct[i] = (int) nodes[i].accept.size();
    }

    queue< int > que;
    for(int i = 0; i < 3; i++) {
      if(~nodes[0].nxt[i]) {
        nodes[nodes[0].nxt[i]].nxt[FAIL] = 0;
        que.emplace(nodes[0].nxt[i]);
      } else {
        nodes[0].nxt[i] = 0;
      }
    }
    while(!que.empty()) {
      TrieNode &now = nodes[que.front()];
      correct[que.front()] += correct[now.nxt[FAIL]];
      que.pop();
      for(int i = 0; i < 2; i++) {
        if(now.nxt[i] == -1) continue;
        int fail = now.nxt[FAIL];
        while(nodes[fail].nxt[i] == -1) {
          fail = nodes[fail].nxt[FAIL];
        }
        nodes[now.nxt[i]].nxt[FAIL] = nodes[fail].nxt[i];

        auto &u = nodes[now.nxt[i]].accept;
        auto &v = nodes[nodes[fail].nxt[i]].accept;
        vector< int > accept;
        set_union(begin(u), end(u), begin(v), end(v), back_inserter(accept));
        u = accept;
        que.emplace(now.nxt[i]);
      }

    }
  }

  pair< int, bool > move(const char c, int now = 0)
  {
    bool match = false;
    while(nodes[now].nxt[c - '0'] == -1) now = nodes[now].nxt[FAIL];
    now = nodes[now].nxt[c - '0'];
    match |= correct[now];
    return {now, match};
  }
};

int length;
string S;
Aho_Corasick PM;

int64 not_cross_cycle()
{
  int PMsz = (int) S.size() + 1;

  vector< vi > curr_dp(2, vi(PMsz));
  curr_dp[0][0] = 1;

  for(int i = 0; i < length; i++) {
    vector< vi > next_dp(2, vi(PMsz));

    for(int j = 0; j < 2; j++) {
      for(int k = 0; k < PMsz; k++) {
        if(curr_dp[j][k] == 0) continue;
        for(char l = '0'; l <= '1'; l++) {
          auto nxt_state = PM.move(l, k);
          next_dp[j | nxt_state.second][nxt_state.first] += curr_dp[j][k];
        }
      }
    }

    curr_dp.swap(next_dp);
  }

  int64 ret = 0;
  for(int i = 0; i < PMsz; i++) {
    ret += curr_dp[1][i];
  }
  return (ret);
}

int64 cross_cycle()
{
  int PMsz = (int) S.size() + 1;

  int matched_state = 0;
  for(auto &p : S) matched_state = PM.move(p, matched_state).first;

  int64 ret = 0;

  for(int begin = length - (int) S.size() + 1; begin < length; begin++) {

    int start = (begin + (int) S.size()) % length;

    vi curr_dp(PMsz);
    curr_dp[matched_state] = 1;
    for(int i = start; i + 1 < begin + S.size(); i++) {
      vi next_dp(PMsz);
      for(int k = 0; k < PMsz; k++) {
        if(curr_dp[k] == 0) continue;
        for(char l = '0'; l <= '1'; l++) {
          if(i >= begin && S[i - begin] != l) continue;
          auto nxt_state = PM.move(l, k);
          if(nxt_state.second && i + 1 >= S.size()) continue;
          next_dp[nxt_state.first] += curr_dp[k];
        }
      }
      curr_dp.swap(next_dp);
    }

    for(int i = 0; i < PMsz; i++) {
      ret += curr_dp[i];
    }

  }

  return (ret);
}

int main()
{
  cin >> length;
  cin >> S;

  if(length < S.size()) {
    // Separate processing
    exit(1);
  }

  PM.add(S);
  PM.build();

  auto sum1 = not_cross_cycle();
  auto sum2 = cross_cycle();

  cout << sum1 + sum2 << endl;
}