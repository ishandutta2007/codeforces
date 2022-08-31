#include<bits/stdc++.h>

using namespace std;

struct TrieNode
{
  int nxt[2];
  int exist; // ??????????????????
  //vector< int > accept; // ?????id

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
    nodes[node].exist += id;
  }

  void update_child(int node, int child, int id)
  {
    nodes[node].exist += id;
  }

  void add(int str, int str_index, int node_index, int id)
  {
    if(str_index == -1) {
      update_direct(node_index, id);
    } else {
      const int c = (str >> str_index) & 1;
      if(nodes[node_index].nxt[c] == -1) {
        nodes[node_index].nxt[c] = (int) nodes.size();
        nodes.push_back(TrieNode());
      }
      add(str, str_index - 1, nodes[node_index].nxt[c], id);
      update_child(node_index, nodes[node_index].nxt[c], id);
    }
  }

  void add(int str, int id)
  {
    add(str, 29, 0, id);
  }

  int query(int str, int t, int str_index, int node_index, int mask)
  {
    if(str_index == -1) {
      return (0);
    } else {
      const int c = (str >> str_index) & 1;

      int next_mask = mask | (1 << str_index);
      int ret = 0;
      if(next_mask >= t) {
        if(c == 1) {
          if(~nodes[node_index].nxt[0]) ret += nodes[nodes[node_index].nxt[0]].exist;
          if(~nodes[node_index].nxt[1]) ret += query(str, t, str_index - 1, nodes[node_index].nxt[1], mask);
        } else {
          if(~nodes[node_index].nxt[1]) ret += nodes[nodes[node_index].nxt[1]].exist;
          if(~nodes[node_index].nxt[0]) ret += query(str, t, str_index - 1, nodes[node_index].nxt[0], mask);
        }
      } else {
        if(c == 1) {
          if(~nodes[node_index].nxt[0]) ret += query(str, t, str_index - 1, nodes[node_index].nxt[0], next_mask);
        } else {
          if(~nodes[node_index].nxt[1]) ret += query(str, t, str_index - 1, nodes[node_index].nxt[1], next_mask);
        }
      }
      return (ret);
    }
  }

  int query(int str, int t)
  {
    return (nodes[0].exist - query(str, t, 29, 0, 0));
  }
};

int main()
{
  int Q;
  scanf("%d", &Q);
  Trie trie;
  while(Q--) {
    int T, P, L;
    scanf("%d %d", &T, &P);
    if(T == 1) {
      trie.add(P, 1);
    } else if(T == 2) {
      trie.add(P, -1);
    } else {
      scanf("%d", &L);
      printf("%d\n", trie.query(P, L));
    }
  }
}