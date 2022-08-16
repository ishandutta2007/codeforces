#include<bits/stdc++.h>

using namespace std;

struct TrieNode
{
  int nxt[27];

  int exist, accept;

  TrieNode() : exist(0), accept(0)
  {
    memset(nxt, -1, sizeof(nxt));
  }
};

struct Trie
{
  vector< TrieNode > nodes;
  vector< string > st;

  Trie()
  {
    nodes.push_back(TrieNode());
  }

  virtual void direct_action(int node, int id) {}

  virtual void child_action(int node, int child, int id) {}

  void update_direct(int node, int id)
  {
    ++nodes[node].accept;
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
    st.push_back(str);
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
      correct[i] = nodes[i].accept;
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
        que.emplace(now.nxt[i]);
      }

    }
  }

  int move(const string &str, int now = 0)
  {
    int ret = 0;
    for(auto &c : str) {
      while(nodes[now].nxt[c - 'a'] == -1) now = nodes[now].nxt[FAIL];
      now = nodes[now].nxt[c - 'a'];
      ret += correct[now];
    }
    return (ret);
  }
};


template< class T >
struct DecomposableSearchingStructure
{
  struct DecomposableSearchingProblem
  {
    T structure;
    int length;

    DecomposableSearchingProblem(T t, int l) : structure(t), length(l) {}

    DecomposableSearchingProblem operator+(const DecomposableSearchingProblem &p)
    {
      return (DecomposableSearchingProblem(structure + p.structure, length + p.length));
    }
  };

  vector< DecomposableSearchingProblem > vs;

  DecomposableSearchingStructure() {}

  void add(const T &st)
  {
    vs.emplace_back(DecomposableSearchingProblem(st, 1));
    while(vs.size() > 1 && vs[vs.size() - 2].length == vs[vs.size() - 1].length) {
      DecomposableSearchingProblem renew(vs[vs.size() - 2] + vs[vs.size() - 1]);
      vs.pop_back(), vs.pop_back();
      vs.push_back(renew);
    }
  }

  size_t size()
  {
    return (vs.size());
  }

  T &operator[](int k)
  {
    return (vs[k].structure);
  }
};


Aho_Corasick operator+(const Aho_Corasick &a, const Aho_Corasick &b)
{
  Aho_Corasick ret;
  for(const string &s : a.st) ret.add(s);
  for(const string &s : b.st) ret.add(s);
  ret.build();
  return (ret);
}

int main()
{
  int N;
  cin >> N;

  DecomposableSearchingStructure< Aho_Corasick > add, rem;

  for(int i = 0; i < N; i++) {
    string S;
    int T;
    cin >> T >> S;
    if(T == 1) {
      Aho_Corasick aho;
      aho.add(S);
      aho.build();
      add.add(aho);
    } else if(T == 2) {
      Aho_Corasick aho;
      aho.add(S);
      aho.build();
      rem.add(aho);
    } else {
      long long ret = 0;
      for(int j = 0; j < add.size(); j++) ret += add[j].move(S);
      for(int j = 0; j < rem.size(); j++) ret -= rem[j].move(S);
      cout << ret << endl;
    }
  }
}