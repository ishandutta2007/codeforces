#include <bits/stdc++.h>

using namespace std;

struct TrieNode
{
  int nxt[27];

  int exist; // ??????????????????
  vector< int > accept; // ?????id

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
      const int c = str[str_index] - 'a';
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
  static const int FAIL = 26;
  vector< int > correct;

  Aho_Corasick() : Trie() {}

  void build()
  {
    correct.resize(nodes.size());
    for(int i = 0; i < nodes.size(); i++) {
      correct[i] = (int) nodes[i].accept.size();
    }

    queue< int > que;
    for(int i = 0; i < 27; i++) {
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
      for(int i = 0; i < 26; i++) {
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

  pair< int, int > move(const char c, int now = 0)
  {
    int match = 0;
    while(nodes[now].nxt[c - 'a'] == -1) now = nodes[now].nxt[FAIL];
    now = nodes[now].nxt[c - 'a'];
    match += correct[now];
    return {now, match};
  }
};


int main()
{
  string S;
  cin >> S;
  string T;
  cin >> T;
  Aho_Corasick aho;
  aho.add(T);
  aho.build();
  set<char>st(T.begin(),T.end());
  vector< int > dp1(T.size() + 1, -1);
  dp1[0] = 0;
  for(int i = 0; i < S.size(); i++) {
    vector< int > dp2(T.size() + 1, -1);
    for(int k = 0; k <= T.size(); k++) {
      if(dp1[k] == -1) continue;
      if(S[i]!='?'){
auto get = aho.move(S[i], k);
          dp2[get.first] = max(dp2[get.first], dp1[k] + get.second);
}else{
      for(char j:st) {
        if(S[i] == '?' || S[i] == j) {
          auto get = aho.move(j, k);
          dp2[get.first] = max(dp2[get.first], dp1[k] + get.second);
        }
      }
}
    }
    dp1.swap(dp2);
  }

  int ret = 0;
  for(auto &k : dp1) ret = max(ret, k);
  cout << ret << endl;
}